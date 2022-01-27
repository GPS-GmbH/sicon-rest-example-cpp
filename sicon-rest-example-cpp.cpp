#include <iostream>
#include <stdlib.h>
#include <string>

#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

// JSON Conversions

class Device {
    public:
        int ID;
        int VendorID;
        int DeviceID;
        string ProductName;
        string VendorName;
        string Description;
};

void from_json(const json& j, Device& sb) {
    sb.ID = j.at("ID");
    sb.VendorID = j.at("VendorID");
    sb.DeviceID = j.at("DeviceID");
    sb.ProductName = j.at("ProductName");
    sb.VendorName = j.at("VendorName");
    sb.Description = j.at("Description");
}

class Devices {
    public:
        vector<Device> devices;
};

void from_json(const json& j, Devices& s) {
    const json& sj = j.at("items");
    s.devices.resize(sj.size());
    copy(sj.begin(), sj.end(), s.devices.begin());
}

class ReportItemProperties {
    public:
        int X_1;
        int X_2;
        int X_3;
        int X_4;
        int Y_1;
        int Y_2;
        int Y_3;
        int Y_4;
        int Y_5;
        int Y_6;
        int Y_7;
        int Y_8;
        int Y_9;
        int Y_10;
        int Y_11;
        int Y_12;
        int Y_13;
        int Y_14;
        int Y_15;
        int Y_16;
        int Y_17;
        int Y_18;
        int Y_19;
        int Y_20;
        int Y_21;
        int Y_22;
        int Y_23;
        int Y_24;
        int Y_25;
        int Y_26;
        int Y_27;
        int Y_28;
        int Y_29;
        int Y_30;
};

void from_json(const json& j, ReportItemProperties& sb) {
    sb.X_1 = (j.contains("X_1") == true) ? int(j.at("X_1")) : -1;
    sb.X_2 = (j.contains("X_2") == true) ? int(j.at("X_2")) : -1;
    sb.X_3 = (j.contains("X_3") == true) ? int(j.at("X_3")) : -1;
    sb.X_4 = (j.contains("X_4") == true) ? int(j.at("X_4")) : -1;
    sb.Y_1 = (j.contains("Y_1") == true) ? int(j.at("Y_1")) : -1;
    sb.Y_2 = (j.contains("Y_2") == true) ? int(j.at("Y_2")) : -1;
    sb.Y_3 = (j.contains("Y_3") == true) ? int(j.at("Y_3")) : -1;
    sb.Y_4 = (j.contains("Y_4") == true) ? int(j.at("Y_4")) : -1;
    sb.Y_5 = (j.contains("Y_5") == true) ? int(j.at("Y_5")) : -1;
    sb.Y_6 = (j.contains("Y_6") == true) ? int(j.at("Y_6")) : -1;
    sb.Y_7 = (j.contains("Y_7") == true) ? int(j.at("Y_7")) : -1;
    sb.Y_8 = (j.contains("Y_8") == true) ? int(j.at("Y_8")) : -1;
    sb.Y_9 = (j.contains("Y_9") == true) ? int(j.at("Y_9")) : -1;
    sb.Y_10 = (j.contains("Y_10") == true) ? int(j.at("Y_10")) : -1;
    sb.Y_11 = (j.contains("Y_11") == true) ? int(j.at("Y_11")) : -1;
    sb.Y_12 = (j.contains("Y_12") == true) ? int(j.at("Y_12")) : -1;
    sb.Y_13 = (j.contains("Y_13") == true) ? int(j.at("Y_13")) : -1;
    sb.Y_14 = (j.contains("Y_14") == true) ? int(j.at("Y_14")) : -1;
    sb.Y_15 = (j.contains("Y_15") == true) ? int(j.at("Y_15")) : -1;
    sb.Y_16 = (j.contains("Y_16") == true) ? int(j.at("Y_16")) : -1;
    sb.Y_17 = (j.contains("Y_17") == true) ? int(j.at("Y_17")) : -1;
    sb.Y_18 = (j.contains("Y_18") == true) ? int(j.at("Y_18")) : -1;
    sb.Y_19 = (j.contains("Y_19") == true) ? int(j.at("Y_19")) : -1;
    sb.Y_20 = (j.contains("Y_20") == true) ? int(j.at("Y_20")) : -1;
    sb.Y_21 = (j.contains("Y_21") == true) ? int(j.at("Y_21")) : -1;
    sb.Y_22 = (j.contains("Y_22") == true) ? int(j.at("Y_22")) : -1;
    sb.Y_23 = (j.contains("Y_23") == true) ? int(j.at("Y_23")) : -1;
    sb.Y_24 = (j.contains("Y_24") == true) ? int(j.at("Y_24")) : -1;
    sb.Y_25 = (j.contains("Y_25") == true) ? int(j.at("Y_25")) : -1;
    sb.Y_26 = (j.contains("Y_26") == true) ? int(j.at("Y_26")) : -1;
    sb.Y_27 = (j.contains("Y_27") == true) ? int(j.at("Y_27")) : -1;
    sb.Y_28 = (j.contains("Y_28") == true) ? int(j.at("Y_28")) : -1;
    sb.Y_29 = (j.contains("Y_29") == true) ? int(j.at("Y_29")) : -1;
    sb.Y_30 = (j.contains("Y_30") == true) ? int(j.at("Y_30")) : -1;
}

class ReportItem {
    public:
        int GlobalCycles;
        ReportItemProperties Properties;
};

void from_json(const json& j, ReportItem& sb) {
    sb.GlobalCycles = j.at("GlobalCycles");
    sb.Properties = j.at("Properties");
}

class Report {
    public:
        vector<ReportItem> History;
};

void from_json(const json& j, Report& sb) {
    const json& sj = j.at("History");
    sb.History.resize(sj.size());
    copy(sj.begin(), sj.end(), sb.History.begin());
}


// REST API Functions

string getToken(RestClient::Connection* conn, string username, string password) {
    conn->AppendHeader("Content-Type", "application/json");
    RestClient::Response response = conn->post(
        "/auth/login",
        "{\"User\": \"" + username + "\", \"Password\": \"" + password + "\"}"
    );
    auto responseBody = json::parse(response.body.c_str());
    string token = responseBody.at("token");
    return token;
}

void setToken(RestClient::Connection* conn, string token) {
    RestClient::HeaderFields headers;
    headers["Authorization"] = "Bearer " + token;
    conn->SetHeaders(headers);
}

vector<Device> getDevices(RestClient::Connection* conn, string query) {
    RestClient::Response response = conn->get("/hardware?" + query);
    json responseBody = json::parse(response.body.c_str());
    Devices devices = responseBody;
    return devices.devices;
}

Report getReportingData(RestClient::Connection* conn, int id, string query) {
    RestClient::Response response = conn->get("/devices/" + to_string(id) + "/reporting?" + query);
    json responseBody = json::parse(response.body.c_str());
    Report report = responseBody;
    return report;
}

int main() {
    cout << "Start\n"; 
    
    string hostname = "https://device.cloud.sicon.eco/api/v1";
    string username = "apiuser";
    string password = "supersecret";
    string deviceQuery = "limit=-1&filter=VendorID=234";

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(hostname);
    
    string token = getToken(conn, username, password);
    setToken(conn, token);
    auto devices = getDevices(conn, deviceQuery);

    auto printHistory = [](ReportItem report) {
        printf("Cycle: %i\t", report.GlobalCycles);
        report.Properties.X_1 != -1 && printf("X_1: %i\t", report.Properties.X_1);
        report.Properties.X_2 != -1 && printf("X_2: %i\t", report.Properties.X_2);
        report.Properties.X_3 != -1 && printf("X_3: %i\t", report.Properties.X_3);
        report.Properties.X_4 != -1 && printf("X_4: %i\t", report.Properties.X_4);
        cout << endl;
        report.Properties.Y_1 != -1 && printf("Y_1: %i\t", report.Properties.Y_1);
        report.Properties.Y_2 != -1 && printf("Y_2: %i\t", report.Properties.Y_2);
        report.Properties.Y_3 != -1 && printf("Y_3: %i\t", report.Properties.Y_3);
        report.Properties.Y_4 != -1 && printf("Y_4: %i\t", report.Properties.Y_4);
        report.Properties.Y_5 != -1 && printf("Y_5: %i\t", report.Properties.Y_5);
        report.Properties.Y_6 != -1 && printf("Y_6: %i\t", report.Properties.Y_6);
        report.Properties.Y_7 != -1 && printf("Y_7: %i\t", report.Properties.Y_7);
        report.Properties.Y_8 != -1 && printf("Y_8: %i\t", report.Properties.Y_8);
        report.Properties.Y_9 != -1 && printf("Y_9: %i\t", report.Properties.Y_9);
        report.Properties.Y_10 != -1 && printf("Y_10: %i\t", report.Properties.Y_10);
        cout << endl;
        report.Properties.Y_11 != -1 && printf("Y_11: %i\t", report.Properties.Y_11);
        report.Properties.Y_12 != -1 && printf("Y_12: %i\t", report.Properties.Y_12);
        report.Properties.Y_13 != -1 && printf("Y_13: %i\t", report.Properties.Y_13);
        report.Properties.Y_14 != -1 && printf("Y_14: %i\t", report.Properties.Y_14);
        report.Properties.Y_15 != -1 && printf("Y_15: %i\t", report.Properties.Y_15);
        report.Properties.Y_16 != -1 && printf("Y_16: %i\t", report.Properties.Y_16);
        report.Properties.Y_17 != -1 && printf("Y_17: %i\t", report.Properties.Y_17);
        report.Properties.Y_18 != -1 && printf("Y_18: %i\t", report.Properties.Y_18);
        report.Properties.Y_19 != -1 && printf("Y_19: %i\t", report.Properties.Y_19);
        report.Properties.Y_20 != -1 && printf("Y_20: %i\t", report.Properties.Y_20);
        cout << endl;
        report.Properties.Y_21 != -1 && printf("Y_21: %i\t", report.Properties.Y_21);
        report.Properties.Y_22 != -1 && printf("Y_22: %i\t", report.Properties.Y_22);
        report.Properties.Y_23 != -1 && printf("Y_23: %i\t", report.Properties.Y_23);
        report.Properties.Y_24 != -1 && printf("Y_24: %i\t", report.Properties.Y_24);
        report.Properties.Y_25 != -1 && printf("Y_25: %i\t", report.Properties.Y_25);
        report.Properties.Y_26 != -1 && printf("Y_26: %i\t", report.Properties.Y_26);
        report.Properties.Y_27 != -1 && printf("Y_27: %i\t", report.Properties.Y_27);
        report.Properties.Y_28 != -1 && printf("Y_28: %i\t", report.Properties.Y_28);
        report.Properties.Y_29 != -1 && printf("Y_29: %i\t", report.Properties.Y_29);
        report.Properties.Y_30 != -1 && printf("Y_30: %i\t", report.Properties.Y_30);
        cout << endl;
    };

    auto printDevices = [conn, printHistory](Device device) {
        cout << "-----------DEVICE-----------" << endl;
        printf("ID: %i\t DeviceID: %i\t VendorID: %i\n", device.ID, device.DeviceID, device.VendorID);
        printf("ProductName: %s\t VendorName: %s\n", device.ProductName.c_str(), device.VendorName.c_str());
        printf("Description: %s\n", device.Description.c_str());
        cout << "-----------REPORT-----------" << endl;

        auto report = getReportingData(conn, device.ID, "samples=4,");
        for_each(report.History.begin(), report.History.end(), printHistory);
    };

    for_each(devices.begin(), devices.end(), printDevices);
 
    cout << "End\n";    
}
