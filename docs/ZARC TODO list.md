# ZARC TODO list

The following list is a running list of items that are currently still uncompleted or require further work. This list was last updated on 03/02/2018.

### Networking

The desired network architecture is as follows: the car connects to the 'eth' network while creating its own 'ZARC' network, to which one can connect to from a laptop. Currently, we have been unable to successfully create a network from either of the WiFi adapters (WiFi module 3 or module 5). See ZARC Assembly Instructions for more details on the mentioned adapters. 

### Wheel Encoders

New hall effect sensor mounts must be contructed in order to reliably estimate the car's forward velocity. Currently, the encoders count wheel turns inaccurately. 

### RC Control

It is possible to utilize the factory RC controller within the ROS framework for ZARC. However, the RC controller exhibits unintuitive behaviour: in order to switch from reverse to forward velocity, the controller must first be forced into a "full reverse throttle" state (the throttle pressed as far as possible in the reverse direction). Please play with the controller briefly to fully understand how this bevahiour manifests itself. It is believed this issue occurs due to a safety mechanism built into the factory controller. More work must be done in order to understand this safety mechanism in order to make RC control more intuitive for the end user. 