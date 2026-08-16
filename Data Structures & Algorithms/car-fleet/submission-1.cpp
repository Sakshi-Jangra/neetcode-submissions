class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int length = position.size();
        double tta = 0;
        vector<pair<int,double>> car;      // {pos, tta}
        stack<double> bottleneck;

        for(int i = 0; i < length; i++){
            tta = (double)(target - position[i])/speed[i];
            car.push_back({position[i], tta});
        }
        sort(car.begin(), car.end(), greater<pair<int,double>>());     // desc order of position
        bottleneck.push(car[0].second);
        for(int i = 1; i < length; i++){
            if(bottleneck.top() < car[i].second){
                bottleneck.push(car[i].second);
            }
        }
        return bottleneck.size();
    }
};
