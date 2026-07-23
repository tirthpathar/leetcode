class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;

        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "+") {
                int first = st.top();
                st.pop();

                int second = st.top();
                int s = first + second;

                st.push(first);
                st.push(s);
            }

            else if(operations[i] == "C") st.pop();

            else if(operations[i] == "D") {
                st.push(2*st.top());
            }

            else {
                st.push(stoi(operations[i]));
            }
        }

        int ans = 0;
        while(st.size() != 0) {

            
            ans += st.top();
            st.pop();
            
        }

        return ans;


        
    }
};