# Moisture Detected Power Cut Off System for Plugs & Plug Sockets

## Overview
This experimental project is designed to create a moisture-detected power cut-off system for plugs and plug sockets. The system, consisting of plug bases and plug tops embedded with Attiny85 microcontrollers, aims to identify moisture on human hands and initiate a power cut-off before the plugin process. This serves as an active hazard prevention system for home appliances.

## Disclaimer
This project is experimental and requires further research and development. The code provided here is tested in the Arduino IDE compiler in 2021, and the project didn't continue beyond that point.

## Key Features
- Moisture detection on human hands.
- Automatic power cut-off to prevent hazards.
- Attiny85 microcontroller-based embedded systems for both plug bases and plug tops.

## Important Notes
- This project is in the experimental stage and requires additional research and development.
- The code is tested in the Arduino IDE compiler in 2021.
- The project did not continue beyond the testing phase.

## How It Works
The Moisture Detected Power Cut Off System for Plugs & Plug Sockets operates with a combination of capacitive sensors, conductive elements, and wireless communication. Here's a brief overview:

1. **Plug Base Design:**
   - The plug base is equipped with capacitive sensors strategically placed to detect human hand touch during the plugin process.

2. **Conductive Elements:**
   - Tiny conductors are embedded in locations where a human hand is likely to be placed during the plugin process. These conductors can detect the presence of conductive materials, such as iron-rich water, which may pose a hazard.

3. **Continuous Monitoring:**
   - The microcontroller within the plug base actively monitors the capacitive sensors and conductive elements continuously.

4. **Moisture Detection:**
   - If the capacitive sensors detect a human hand touch and the conductive elements sense the presence of conductive material, indicating a potential hazard, the system initiates moisture detection.

5. **Wireless Communication:**
   - The plug base communicates wirelessly with plug tops using a simple 433MHz RF protocol.

6. **Power Cut-Off Signal:**
   - Upon detecting moisture and potential hazards, the plug base sends a power cut-off signal to the plug tops.

7. **Power Cut-Off Mechanism:**
   - The plug tops receive the signal and actively cut off power to prevent hazards. This is achieved by opening the connection within the plug bases.

8. **Safe Activation:**
   - After the plug base detects that the hand is removed and the hazard is cleared, it safely feeds current to the equipment, allowing normal operation.

This comprehensive system ensures a safe plugin process by actively monitoring and responding to moisture and potential conductive materials, providing an additional layer of protection for home appliances.

## Getting Started
1. Clone this repository to your local environment.
2. Open the Arduino IDE and load the respective code for plug bases or plug tops.
3. Configure the necessary parameters in the code.
4. Upload the code to the Attiny85 microcontrollers.
5. Monitor the console for debugging information.

## Contributing
Feel free to contribute to the project by submitting bug reports, feature requests, or pull requests. Since this is an experimental project, any additional insights or improvements are welcome.

## Author
Isuru Ranaweera
GitHub: [isuru-rana](https://github.com/Isuru-rana)

## License
This project is licensed under the [MIT License](LICENSE).

---

**Note:** This project is experimental and provided for educational purposes only. Always adhere to safety guidelines and regulations when working with electrical systems.
