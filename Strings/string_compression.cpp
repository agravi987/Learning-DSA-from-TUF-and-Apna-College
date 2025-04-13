class Solution {
    public:
        int compress(vector<char>& chars) {
            int index = 0 ; 
            int i = 0 ; 
            int n = chars.size() ; 
    
            while(i<n){
                char current = chars[i] ; 
                int count = 0 ; 
    
                while(i<n && chars[i] == current){
                    i++ ; 
                    count++ ; 
                }
    
                chars[index++] = current ; 
    
                if(count > 1){
                    for(char ch : to_string(count)){
                        chars[index++] = ch ; 
                    }
                }
            }
    
            return index ; 
        }
    };