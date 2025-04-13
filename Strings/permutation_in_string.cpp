class Solution {
    public:
    
        bool isFreqSame(int arr1[] , int arr2[]){
            for(int i = 0 ; i<26 ; i++){
                if(arr1[i]  != arr2[i]){
                    return false ; 
                }
            }
    
            return true ; 
        }
    
    
        bool checkInclusion(string s1, string s2) {
            
            int freq[26] = {0} ; 
            
            for(char ch : s1){
                freq[ ch - 'a']++ ; 
            }
    
            int winSize = s1.length() ; 
    
            for(int i = 0 ; i<s2.length() ; i++){
                int winIdx = 0 , idx = i ; 
                int windFreq[26] = {0} ; 
    
                while(winIdx < winSize && idx < s2.length()){
                    windFreq[s2[idx] - 'a']++ ; 
                    winIdx++ ; 
                    idx++ ; 
    
                }
    
    
                if(isFreqSame(freq , windFreq)){
                    return true ; 
                }
            }
    
            return false  ;
            
        }
    };