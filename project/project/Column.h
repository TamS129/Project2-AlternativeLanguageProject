#pragma once
#ifndef COLUMN_H
#define COLUMN_H

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
    Column();

    Column(string o, string m, int la, string ls, string bd, float bw, string bs, string dt, float ds, string dr, string fs, string po);
    // Getter Methods
    std::string getOem() const;
    std::string getModel() const;
    int getLaunchedAnnounced() const;
    std::string getLaunchStatus() const;
    std::string getBodyDim() const;
    float getBodyWeight() const;
    std::string getBodySim() const;
    std::string getDisplayType() const;
    float getDisplaySize() const;
    std::string getDisplayRes() const;
    std::string getFeatSens() const;
    std::string getPlatOS() const;


    // Setter Methods
    void setOem(string newOem);
    void setModel(string newModel);
    void setLaunchedAnnounced(int newLaunch);
    void setLaunchStatus(string newStatus);
    void setBodyDim(string newBodyDim);
    void setBodyWeight(float newBw);
    void setBodySim(string newBS);
    void setDisplayType(string newDT);
    void setDisplaySize(float newDS);
    void setDisplayRes(string newDRes);
    void setFeatSens(string newFeat);
    void setPlatOS(string newPlatOS);

    friend std::ostream& operator<<(std::ostream& os, const Column& column);

};
#endif // COLUMN_H