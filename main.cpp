/*Definition: Single class with global access to achieve multiple instance
*/
#include <iostream>
#include <string>
using namespace std;


class MeterConfiguration{
    static MeterConfiguration *instance;
    string MeterType;
    string MeterVersion;
    MeterConfiguration ()
    {
        MeterType = "3PH";
        MeterVersion = "3PH-X-Y-Z";
    }
public:
    static MeterConfiguration *GetMeterConfigurationInstance()
    {
        if (instance == NULL)
        {
            instance = new MeterConfiguration();
            return instance;
        }
        else
        {
            return instance;
        }
    }

    // Setter function
    void setMeterType(string meterType)
    {
        MeterType = meterType;
    }

    void setMeterVersion(string meterVersion)
    {
        MeterVersion = meterVersion;
    }

    //getter function

    string getMeteType()
    {
        return MeterType;
    }
    string getMeterVersion()
    {
        return MeterVersion;
    }

    void ShowMeterConfiguration()
    {
        cout<< "MeterType:     " << MeterType << endl;
        cout<< "MeterVersion:  " << MeterVersion << endl<<endl;
    }
};

MeterConfiguration * MeterConfiguration :: instance = NULL;

void Configuration()
{
    MeterConfiguration *mc = MeterConfiguration:: GetMeterConfigurationInstance();
    cout << "Default MeterType:     "<< mc->getMeteType()<<endl;
    cout << "Default MeterVersion:  "<< mc->getMeterVersion()<<endl;
    mc->setMeterType("1PH");
    mc->setMeterVersion("1PH-A-B-C");
}
int main()
{
    MeterConfiguration *MG1 = MeterConfiguration:: GetMeterConfigurationInstance();
    MG1->ShowMeterConfiguration();
    Configuration();
    MG1->ShowMeterConfiguration();
    return 0;
}

