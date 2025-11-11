class UndergroundSystem {
    map<int,pair<string,int>> checkin;
    // map<int,pair<string,int>> checkout;
    map<string,map<string,pair<int,int>>> mp;
    // pair=total,count
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkin[id];
        int travelTime = t - startTime;

        auto &[total, count] = mp[startStation][stationName];
        total += travelTime;
        count += 1;

        checkin.erase(id); // remove after checkout
    }

    double getAverageTime(string startStation, string endStation) {
        auto [total, count] = mp[startStation][endStation];
        if (count == 0) return 0.0;
        return (double) total / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */