class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<unordered_map<string,int>> table(501);
        set<string> food;
        for(int i = 0; i<orders.size();i++){
           food.insert(orders[i][2]);
            table[stoi(orders[i][1])][orders[i][2]]++;
        }
        
        vector<vector<string>> ans;
        vector<string> row;
        row.push_back("Table");
        for(auto it = food.begin();it!=food.end();it++){
            row.push_back(*it);
        }
        ans.push_back(row);
        row.clear();
        for(int  t = 1; t < 501; t++){
            if(table[t].empty()) continue;
            row.clear();
           row.push_back(to_string(t));
            for(auto it = food.begin();it!=food.end();it++){

                row.push_back(to_string(table[t][*it]));
            }
            ans.push_back(row);
          }
        return ans;
        
    }
};
