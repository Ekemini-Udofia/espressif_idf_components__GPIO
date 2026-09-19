ESP-IDF GPIO button example

This project is a simple ESP-IDF application that demonstrates how to use the Espressif button component to detect GPIO button presses and trigger callbacks.

What the project does
- Configures GPIO 7 as the button input.
- Uses active-low logic, meaning the button is considered pressed when the input is low.
- Registers callbacks for single-click and double-click events.
- Prints messages to the serial monitor when each event occurs.

Files in the project
- main/main.c: Contains the application logic.
- main/CMakeLists.txt: Registers the main source file with the ESP-IDF build system.
- main/idf_component.yml: Declares the dependency on the Espressif button component.
- CMakeLists.txt: Standard ESP-IDF project configuration.

Required dependencies
- ESP-IDF version 4.1 or newer
- Espressif button component version 4.2.1 or compatible

Hardware setup
- Connect a push button between GPIO 7 and ground.
- Use the internal pull-up or an external pull-up resistor, depending on your circuit design.
- The code defines BUTTON_ACTIVE_LEVEL as 0, so the button is active when the GPIO reads low.

Build and run
1. Open a terminal in the project folder.
2. Set up the ESP-IDF environment if needed.
3. Run:
   idf.py build
4. Flash the firmware:
   idf.py flash
5. Monitor the output:
   idf.py monitor

Expected behavior
When you press the button once, the application logs a single click event. When you press it twice quickly, it logs a double click event.

Note
This is a basic example intended to show GPIO button handling and event callback registration using the ESP-IDF component manager.
