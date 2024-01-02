{
  "700": {
    "name": "Operating mode",
    "dataType_name": "ENUM",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 65535, "desc": "---" },
      { "enumValue": 0, "desc": "Protection" },
      { "enumValue": 1, "desc": "Automatic" },
      { "enumValue": 2, "desc": "Reduced" },
      { "enumValue": 3, "desc": "Comfort" }
    ],
    "isswitch": 0,
    "dataType": 1,
    "readonly": 0,
    "readwrite": 0,
    "unit": ""
  },
    "710": {
    "name": "Comfort setpoint ",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "°C"
  },
  "712": {
    "name": "Room temp reduced setpoint",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "°C"
  },
  "900": {
    "name": "Operating mode changeover",
    "dataType_name": "ENUM",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 65535, "desc": "---" },
      { "enumValue": 0, "desc": "None" },
      { "enumValue": 1, "desc": "Protection" },
      { "enumValue": 2, "desc": "Reduced" },
      { "enumValue": 3, "desc": "Comfort" },
      { "enumValue": 4, "desc": "Automatic" }
    ],
    "isswitch": 0,
    "dataType": 1,
    "readonly": 0,
    "readwrite": 0,
    "unit": ""
  }
  "1600": {
    "name": "Operating mode",
    "dataType_name": "ENUM",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 65535, "desc": "---" },
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "On" },
      { "enumValue": 2, "desc": "Eco" }
    ],
    "isswitch": 0,
    "dataType": 1,
    "readonly": 0,
    "readwrite": 0,
    "unit": ""
  },
  "1610": {
    "name": "DHW temperature nominal setpoint",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "°C"
  },
  "1612": {
    "name": "DHW temperature reduced setpoint",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "°C"
  },
  "2843": {
    "name": "Compressor off time min",
    "dataType_name": "MINUTES_SHORT",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "min"
  },
  "2870": {
    "name": "Compressor modulation max",
    "dataType_name": "PERCENT",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "%"
  },
  "2871": {
    "name": "Compressor modulation min",
    "dataType_name": "PERCENT",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "%"
  },
  "8406": {
    "name": "State condenser pump",
    "dataType_name": "ONOFF",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "On" }
    ],
    "isswitch": 1,
    "dataType": 1,
    "readonly": 1,
    "readwrite": 1,
    "unit": ""
  },
    "8410": {
    "name": "Return temperature heat pump",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8411": {
    "name": "Setpoint heat pump",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8412": {
    "name": "Flow temp heat pump",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8413": {
    "name": "Compressor modulation",
    "dataType_name": "PERCENT",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "%"
  },
  "8425": {
    "name": "Temperature differential condenser",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8700": {
    "name": "Outside temp",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  }
  "8703": {
    "name": "Outside temp attenuated",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "°C"
  },
  "8704": {
    "name": "Outside temp composite",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8730": {
    "name": "Status heat circuit pump 1",
    "dataType_name": "ONOFF",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "On" }
    ],
    "isswitch": 1,
    "dataType": 1,
    "readonly": 1,
    "readwrite": 1,
    "unit": ""
  },
  "8731": {
    "name": "Status heat circuit mixing valve 1 opens",
    "dataType_name": "ONOFF",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "On" }
    ],
    "isswitch": 1,
    "dataType": 1,
    "readonly": 1,
    "readwrite": 1,
    "unit": ""
  },
  "8732": {
    "name": "Status heat circuit mixing valve 1 closes",
    "dataType_name": "ONOFF",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "On" }
    ],
    "isswitch": 1,
    "dataType": 1,
    "readonly": 1,
    "readwrite": 1,
    "unit": ""
  },
  "8735": {
    "name": "Heat circuit pump speed HC1",
    "dataType_name": "PERCENT",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "%"
  },
  "8740": {
    "name": "Room temperature actual value 1",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8741": {
    "name": "Room temperature setpoint 1",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8742": {
    "name": "Room temperature model 1",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 0,
    "readwrite": 0,
    "unit": "°C"
  },
  "8743": {
    "name": "Flow temp actual value heat circuit 1",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
    "8937": {
    "name": "Ventilation stage 1",
    "dataType_name": "ENUM",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 65535, "desc": "---" },
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "stage 1" },
      { "enumValue": 2, "desc": "stage 2" },
      { "enumValue": 3, "desc": "stage 3" }
    ],
    "isswitch": 0,
    "dataType": 1,
    "readonly": 1,
    "readwrite": 1,
    "unit": ""
  },
  "8942": {
    "name": "Ventilation stage 2",
    "dataType_name": "ENUM",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 65535, "desc": "---" },
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "stage 1" },
      { "enumValue": 2, "desc": "stage 2" },
      { "enumValue": 3, "desc": "stage 3" }
    ],
    "isswitch": 0,
    "dataType": 1,
    "readonly": 1,
    "readwrite": 1,
    "unit": ""
  },
  "8947": {
    "name": "Ventilation stage 3",
    "dataType_name": "ENUM",
    "dataType_family": "ENUM",
    "destination": "0",
    "possibleValues": [
      { "enumValue": 65535, "desc": "---" },
      { "enumValue": 0, "desc": "Off" },
      { "enumValue": 1, "desc": "stage 1" },
      { "enumValue": 2, "desc": "stage 2" },
      { "enumValue": 3, "desc": "stage 3" }
    ],
    "isswitch": 0,
    "dataType": 1,
    "readonly": 1,
    "readwrite": 1,
    "unit": ""
  },
  "8950": {
    "name": "Segment flow temperature actual value",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },
  "8951": {
    "name": "Segment flow temperature setpoint",
    "dataType_name": "TEMP",
    "dataType_family": "VALS",
    "destination": "0",
    "possibleValues": [

    ],
    "isswitch": 0,
    "precision": 0.1,
    "dataType": 0,
    "readonly": 1,
    "readwrite": 1,
    "unit": "°C"
  },

}