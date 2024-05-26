#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class Column {
private:
    string oem;
    string model;
    int launch_announced;
    string launch_status;
    string body_dimensions;
    float body_weight;
    string body_sim;
    string display_type;
    float display_size;
    string display_resolution; 
    string feature_sensors;
    string platform_os;

public:
    Column() {}

    Column(string o, string m, int la, string ls, string bd, float bw, string bs, string dt, float ds, string dr, string fs, string po) 
        : oem(o), model(m), launch_announced(la), launch_status(ls), body_dimensions(bd), body_weight(bw), body_sim(bs),
          display_type(dt), display_size(ds), display_resolution(dr), feature_sensors(fs), platform_os(po) {}

    // Getter Methods
    string getOem() { return oem; }
    string getModel() { return model; }
    int getLaunchedAnnounced() { return launch_announced; }
    string getLaunchStatus() { return launch_status; }
    string getBodyDim() { return body_dimensions; }
    float getBodyWeight() { return body_weight; }
    string getBodySim() { return body_sim; }
    string getDisplayType() { return display_type; }
    float getDisplaySize() { return display_size; }
    string getDisplayRes() { return display_resolution; }
    string getFeatSens() { return feature_sensors; }
    string getPlatOS() { return platform_os; }

    // Setter Methods
    void setOem(string newOem) { oem = newOem; }
    void setModel(string newModel) { model = newModel; }
    void setLaunchedAnnounced(int newLaunch) { launch_announced = newLaunch; }
    void setLaunchStatus(string newStatus) { launch_status = newStatus; }
    void setBodyDim(string newBodyDim) { body_dimensions = newBodyDim; }
    void setBodyWeight(float newBw) { body_weight = newBw; }
    void setBodySim(string newBS) { body_sim = newBS; }
    void setDisplayType(string newDT) { display_type = newDT; }
    void setDisplaySize(float newDS) { display_size = newDS; }
    void setDisplayRes(string newDRes) { display_resolution = newDRes; }
    void setFeatSens(string newFeat) { feature_sensors = newFeat; }
    void setPlatOS(string newPlatOS) { platform_os = newPlatOS; }
};