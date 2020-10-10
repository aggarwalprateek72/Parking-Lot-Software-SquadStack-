#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;

class Parking{
public:

    int num_cars_slots;
    priority_queue<int,vector<int>,greater<int>> total_slots;
    unordered_map<string,int> registration_to_age;
    unordered_map<int,string> slot_to_reg_num;
    unordered_map<int,vector<string>> all_cars_regno_for_age;
    unordered_map<string,int> registration_to_slot;
    unordered_map<int,vector<int>> all_carslot_for_age;

    Parking(){

    }
    Parking(int num_cars_slots){
        this->num_cars_slots=num_cars_slots;
        for(int i=1;i<=num_cars_slots;++i){
            total_slots.push(i);
        }
    }
    //Method to register new user to an empty parking slot. If no slot is empty, this method would return false
    string register_new_vehicle(string reg_no, int age){
        if(total_slots.empty()){
            return "";
        }
        int slot_alloted=total_slots.top();
        total_slots.pop();
        registration_to_age[reg_no]=age;
        all_cars_regno_for_age[age].push_back(reg_no);
        slot_to_reg_num[slot_alloted]=reg_no;
        registration_to_slot[reg_no]=slot_alloted;
        all_carslot_for_age[age].push_back(slot_alloted);
        string message="Car with vehicle registration number "+reg_no+" has been parked at slot number "+to_string(slot_alloted);
        return message;
    }


    //Method to return all the slot numbers of cars for a given age, which if invalid would return empty vector(null)
    vector<int> fetch_all_slots_for_age(int age){
        if(all_carslot_for_age.find(age)!=all_carslot_for_age.end()){
            return all_carslot_for_age[age];
        }
        return {};
    }
    //Method to return the parking slot for a given registration number, which if invalid would return -1
    int fetch_slot_number_for_reg_no(string reg_no){
        if(registration_to_slot.find(reg_no)!=registration_to_slot.end()){
            return registration_to_slot[reg_no];
        }
        return -1;
    }

    // Method to return all the registration numbers of cars for a given age, which if invalid would return empty vector(null)
    vector<string> fetch_all_reg_no_for_age(int age){
        if(all_cars_regno_for_age.find(age)!=all_cars_regno_for_age.end()){
            return all_cars_regno_for_age[age];
        }
        return {};
    }

    //Method to empty the parking slot when the user leaves for given slot, and thus clearing all its stored value, which if invalid, returns empty message
    string user_leaving_parking(int slot_num){
        if(slot_to_reg_num.find(slot_num)==slot_to_reg_num.end()){
            return "";
        }

        string registration_number=slot_to_reg_num[slot_num];
        int age=registration_to_age[slot_to_reg_num[slot_num]];
        string message="Slot number "+ to_string(slot_num) + " vacated, the car with vehicle registration number "+ registration_number+ " left the space,";
        string driver_age=" the driver of the car was of age "+ to_string(age);
        slot_to_reg_num.erase(slot_num);
        registration_to_age.erase(registration_number);
        registration_to_slot.erase(registration_number);
        all_carslot_for_age[age].erase(remove(all_carslot_for_age[age]. begin(), all_carslot_for_age[age]. end(), slot_num), all_carslot_for_age[age]. end());
        all_cars_regno_for_age[age].erase(remove(all_cars_regno_for_age[age]. begin(), all_cars_regno_for_age[age]. end(), registration_number), all_cars_regno_for_age[age]. end());
        total_slots.push(slot_num);
        return message+driver_age;
    }

};

//Adding the extension at the end of file if needed, otherwise reading the file for processing
void converting_to_valid_file_format(string &fil_name){
    if(fil_name.length()<4){
        fil_name+=".txt";
    }else{
        string check_for_ext=fil_name.substr(fil_name.length()-4);
        if(check_for_ext!=".txt"){
            fil_name+=".txt";
        }
    }
}

//Method to check if file which needs to be processed exists or not
bool check_file_presence(string file_name){
    ifstream infile(file_name);
    return infile.good();
}
//Reading the file input
vector<string> process_file_input(string file_name){
    if(check_file_presence(file_name)==false){
        cout<<"Invalid File Name. Check for Case Sensitive"<<endl;
        return {};
    }
    vector<string> result_to_save;
    ifstream file (file_name);
    string str;
    if(file.is_open()){
        getline(file,str);
        vector<string> temp_token_for_slots;
        stringstream c1(str);
        string inter;
        // Tokenizing w.r.t. space ' ' for number of slots
        while(getline(c1, inter, ' '))
        {
            temp_token_for_slots.push_back(inter);
        }
        result_to_save.push_back("Created parking of "+temp_token_for_slots[1] +" slots");
        Parking obj(stoi(temp_token_for_slots[1]));
        while(getline(file,str)){
            vector <string> tokens;
            // stringstream class to split string into tokens
            stringstream check1(str);
            string intermediate;
            // Tokenizing w.r.t. space ' '
            while(getline(check1, intermediate, ' '))
            {
                tokens.push_back(intermediate);
            }
            //Register new user for Parking Lot
            if(tokens[0]=="Park" && tokens.size()==4){
                string message=obj.register_new_vehicle(tokens[1],stoi(tokens[3]));
                if(message.length()==0){
                    result_to_save.push_back("No Empty Parking Space");
                }else{
                    result_to_save.push_back(message);
                }
                continue;
            }
            //Fetch All Slot numbers issued to given age
            if(tokens[0]=="Slot_numbers_for_driver_of_age" && tokens.size()==2){
                vector<int> resultant_slots=obj.fetch_all_slots_for_age(stoi(tokens[1]));

                string message="";
                for(int i=0;i<resultant_slots.size()-1;++i){
                    message+=to_string(resultant_slots[i])+",";
                }
                if(resultant_slots.size()==0){
                    result_to_save.push_back("NULL");
                }else{
                    message+=to_string(resultant_slots[resultant_slots.size()-1]);
                    result_to_save.push_back(message);
                }
                continue;
            }
            //fetch all the slot numbers with given registration Numbers
            if(tokens[0]=="Slot_number_for_car_with_number" && tokens.size()==2){
                int resultant_slot=obj.fetch_slot_number_for_reg_no(tokens[1]);
                if(resultant_slot==-1){
                    result_to_save.push_back("No such Car is Present");
                    continue;
                }else{
                    result_to_save.push_back(to_string(resultant_slot));
                }
                continue;
            }
            //User leaving the parking lot
            if(tokens[0]=="Leave" && tokens.size()==2){
                string result_msg= obj.user_leaving_parking(stoi(tokens[1]));
                if(result_msg.length()==0){
                    result_to_save.push_back("No Car is Present at Slot Number "+tokens[1]);
                }else{
                    result_to_save.push_back(result_msg);
                }
            }
            //Fetch all registration numbers for given age
            if(tokens[0]=="Vehicle_registration_number_for_driver_of_age" && tokens.size()==2){
                vector<string> resultant_regs= obj.fetch_all_reg_no_for_age(stoi(tokens[1]));
                if(resultant_regs.size()==0){
                    result_to_save.push_back("No Registration Numbers for Given age has been parked.");
                }else{
                    string message="";
                    for(int i=0;i<resultant_regs.size()-1;++i){
                        message+=resultant_regs[i]+",";
                    }
                    message+=resultant_regs[resultant_regs.size()-1];
                    result_to_save.push_back(message);
                }
                continue;
            }
            result_to_save.push_back("Invalid Command");
        }
    }
    return result_to_save;
}

//Writing output to new file
void resultant_file_output(vector<string> output){
    std::ofstream output_file("output.txt");
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(output.begin(), output.end(), output_iterator);
    return;
}

int main(){
    int ask_for_mode;
    cout<<"Parking Lot "<<endl;
    cout<<"Select Option: "<<endl;
    cout<<"1. A filename as an input argument to executes the commands from the given file"<<endl;
    cout<<"2. Exit"<<endl;
    cin>>ask_for_mode;
    if(ask_for_mode==1){
      cout<<"Enter File Name (must be of .txt format)"<<endl;
      string fil_name;
      cin>>fil_name;
      converting_to_valid_file_format(fil_name);
      vector<string> output=process_file_input(fil_name);
      if(output.size()==0){
        exit(0);
      }
      resultant_file_output(output);
      cout<<"Results have been added to the output file named [output.txt]"<<endl;
    }else if(ask_for_mode==2){
        exit(0);
    }else{
        cout<<"Invalid Option."<<endl;
    }
    cout<<"Exiting the Parking Lot System...";
    exit(0);
    return 0;
}
