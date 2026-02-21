#include <iostream>
#include <queue>
#include <string>
#include <vector>
using std::priority_queue, std::cout, std::endl, std::string, std::vector;

struct SensorReading {
  int sensorId;
  string location;
  string sensorType;
  double value;
};

struct Alert {
  int priority;
  string message;
  string alertType;

  bool operator<(const Alert &other) const {
    return this->priority < other.priority;
  }
};

class SensorProcessor {
private:
  vector<SensorReading> sensors;
  priority_queue<Alert> alerts;

public:
  void addSensorReading(const SensorReading &reading) {
    sensors.push_back(reading);
  }

  void addAlert(const Alert &alert) { alerts.push(alert); }

  void processNextAlert() {
    if (alerts.empty()) {
      std::cout << "No alerts." << std::endl;
      return;
    }
    std::cout << alerts.top().message << std::endl;
    alerts.pop();
  }

  SensorReading *findSensorById(int sensorId) {
    for (size_t i = 0; i < sensors.size(); i++) {
      if (sensors[i].sensorId == sensorId) {
        return &sensors[i];
      }
    }
    return nullptr;
  }

  vector<SensorReading> getSensorsByLocation(const string &location) {
    vector<SensorReading> result;

    for (size_t i = 0; i < sensors.size(); i++) {
      if (sensors[i].location == location) {
        result.push_back(sensors[i]);
      }
    }

    return result;
  }
};

int main() {
  SensorProcessor processor;

  // 1. Add some sensor readings
  processor.addSensorReading({101, "Building_A", "Temperature", 25.5});
  processor.addSensorReading({102, "Building_B", "Humidity", 45.0});
  processor.addSensorReading({103, "Building_A", "Smoke", 0.02});

  // 2. Test ID Lookup
  cout << "--- Testing ID Lookup ---" << endl;
  SensorReading *s = processor.findSensorById(102);
  if (s) {
    cout << "Found Sensor 102 in " << s->location << " (Value: " << s->value
         << ")" << endl;
  } else {
    cout << "Sensor 102 not found." << endl;
  }

  // 3. Test Location Retrieval
  cout << "\n--- Testing Location Retrieval (Building_A) ---" << endl;
  vector<SensorReading> buildingA =
      processor.getSensorsByLocation("Building_A");
  for (const auto &sensor : buildingA) {
    cout << "Sensor ID: " << sensor.sensorId << " Type: " << sensor.sensorType
         << endl;
  }

  // 4. Test Priority Alerts
  cout << "\n--- Testing Priority Alerts (Highest First) ---" << endl;
  processor.addAlert({1, "Routine maintenance check", "INFO"});
  processor.addAlert({10, "FIRE DETECTED!", "CRITICAL"});
  processor.addAlert({5, "High temperature warning", "WARNING"});

  // Should print Fire (10), then High temp (5), then Routine (1)
  processor.processNextAlert();
  processor.processNextAlert();
  processor.processNextAlert();

  // 5. Test Empty Queue Edge Case
  cout << "\n--- Testing Empty Alert Queue ---" << endl;
  processor.processNextAlert();

  return 0;
}
