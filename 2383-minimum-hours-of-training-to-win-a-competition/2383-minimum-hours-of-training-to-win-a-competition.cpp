class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        // int max_exp = max(experience.begin(), experience.end());
        int max_exp = *max_element(experience.begin(), experience.end());
        int sum = accumulate(energy.begin(), energy.end(), 0);
        int hour = 0;
        if(sum >= initialEnergy){
            hour = sum - initialEnergy + 1;  
        }
        if(initialExperience <= max_exp){
            int i = 0;
            while(i < experience.size() && initialExperience <= max_exp){// && initialExperience <= max_exp
                if(experience[i] >= initialExperience){
                    hour += experience[i] - initialExperience + 1;
                    initialExperience += 2*experience[i++] - initialExperience + 1;
                    continue;
                }
                initialExperience += experience[i++];
            }
        }
        
           return hour;
//         int hour = 0;
//         for(int i = 0; i < energy.size(); i++){
//             if(initialEnergy <= energy[i]){
//                 hour += energy[i] - initialEnergy + 1;
//             }
//             initialEnergy -= 
            
//             if(initialExperience){
                
//             }
//         }
    }
};