# Project Gallery

[Back to the project overview](../../README.md)

Photos of the physical smart home model, its electronics and the original design. Click any image to open the full-size file.

## Physical Model

The model includes room partitions, a driveway, gates, doors, LED lighting, MQ-9 gas sensors and ventilation fans.

| Front view | Model overview |
| --- | --- |
| [<img src="physical-model/front-view.png" alt="Front view of the completed smart home model" width="360">](physical-model/front-view.png) | [<img src="physical-model/overview.png" alt="Elevated view of the model showing the rooms, driveway and yard" width="360">](physical-model/overview.png) |

| Room layout and sensors | Entrance and driveway |
| --- | --- |
| [<img src="physical-model/top-view.png" alt="Top view showing the room layout, gas sensors, ventilation fans and LEDs" width="360">](physical-model/top-view.png) | [<img src="physical-model/entrance-and-driveway.png" alt="View through the front gates toward the garage and entrance door" width="360">](physical-model/entrance-and-driveway.png) |

## Electronics and Mechanisms

The electronics are mounted beneath the model. The Raspberry Pi communicates with the Arduino Mega over USB, while servos and mechanical linkages operate the gates and doors.

| Electronics beneath the model | Controllers and relay modules |
| --- | --- |
| [<img src="physical-model/electronics-side-view.png" alt="Side view of the lower electronics platform beneath the model" width="360">](physical-model/electronics-side-view.png) | [<img src="physical-model/controllers-and-relays.png" alt="Raspberry Pi, Arduino Mega, relay modules and connecting wires" width="360">](physical-model/controllers-and-relays.png) |

**Servos and mechanical linkages**

[<img src="physical-model/servos-and-linkages.png" alt="Servos and mechanical linkages mounted on the lower platform" width="560">](physical-model/servos-and-linkages.png)

## 3D Model

These renders show the building geometry and room layout. The STL file is available in [hardware/models](../../hardware/models/).

| Perspective view | Front view |
| --- | --- |
| [<img src="3d-renders/perspective-view.png" alt="Perspective render of the smart home building model" width="360">](3d-renders/perspective-view.png) | [<img src="3d-renders/front-view.png" alt="Front render showing the garage, entrance and perimeter wall" width="360">](3d-renders/front-view.png) |

| Top view | Front angle |
| --- | --- |
| [<img src="3d-renders/top-view.png" alt="Top-down render showing the room layout" width="360">](3d-renders/top-view.png) | [<img src="3d-renders/front-angle.png" alt="Angled render of the front elevation and driveway" width="360">](3d-renders/front-angle.png) |

| Rear angle | Interior view |
| --- | --- |
| [<img src="3d-renders/rear-angle.png" alt="Render of the rear and side walls" width="360">](3d-renders/rear-angle.png) | [<img src="3d-renders/interior-view.png" alt="Close-up render of the interior partitions and door openings" width="360">](3d-renders/interior-view.png) |

## Circuit Schematics

The three sheets document the main controller connections, servo control circuits, gas sensors, fans and LED lighting. Editable KiCad files are available in [hardware/kicad/SmartHome](../../hardware/kicad/SmartHome/).

### Main Controller

[![Main controller schematic with Arduino Mega 2560, power supply and peripheral connections](schematics/main-controller.png)](schematics/main-controller.png)

### Servo Control

[![Servo control schematic with relay drivers and PWM connections](schematics/servo-control.png)](schematics/servo-control.png)

### Gas Sensors, Fans and Lighting

[![Schematic of MQ-9 gas sensors, fan relay drivers and LED lighting circuits](schematics/sensors-fans-lighting.png)](schematics/sensors-fans-lighting.png)

## Web Dashboard

The Flask dashboard provides controls for six servo-operated elements and ten LED lighting points. The screenshot shows the original Polish interface running on the local network.

[![Flask web dashboard with servo and LED controls](web-dashboard.png)](web-dashboard.png)
