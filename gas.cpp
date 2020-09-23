class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> index;
        
        bool invalid = true;
        for( int i = 0; i<cost.size(); i++ ){
            if(gas[i]>=cost[i]){
                index.push_back(i);
                invalid = false;
            }
        }
        
        if(invalid)
            return -1;
        int curidx = index[0];
        int saved_curidx = index[0];
        int count = index.size();
        index.erase(index.begin());
        int travelcost = 0;
        int itr = 0;
        bool first = true;
        bool success = true;
        
        for(int i = 0; i<count;i++ ){
            
                       
            for(int j = 0; j<cost.size()+1;j++ ){
      
                if(first){
                    travelcost = gas[curidx+itr]-cost[curidx+itr];

                }
                if(!first){
                    travelcost+=gas[curidx+itr];
                    travelcost = travelcost-cost[curidx+itr];
                }
                if( travelcost <  0){
                    success = false;
                    break;
                }
                if(curidx+itr == gas.size()-1){
                    curidx = 0;
                    itr = 0;
                }else{
                    itr++;
                    }
                first = false;

                }
            if(success){
                return saved_curidx;
            }
            
            if( i == count-1){
                break;
            }
            first = true;
            success = true;
            itr = 0;
            curidx = index[0];
            saved_curidx = index[0];
            index.erase(index.begin());
            }
        return -1;
        }
};

