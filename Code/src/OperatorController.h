/*
 * OperatorController.h
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_OPERATORCONTROL_H_
#define SRC_OPERATORCONTROL_H_

#include "Joystick.h"
#include "DriveController.h"
#include "LiftController.h"
#include "StingerController.h"
#include "RampController.h"
#include "Timer.h"


class OperatorController {
public:
	OperatorController(DriveController &driveCtlr,
					LiftController &liftCtlr,
					StingerController &stingerCtlr,
					int stickLChan,
					int stickRChan);
	virtual ~OperatorController();
	void Run();
	void updateHatSetpoints(Joystick &stick);
	void updateSetpointButton(Joystick &stick);

private:

	bool isDeadzone(float x, float y);

	DriveController &driveController;
	LiftController &liftController;
	StingerController &stingerController;
	Joystick stickRight;
	Joystick stickLeft;

	float strafe;
	float forward;
	float rotation;
	int hatPosition;

	static const float MAX_ROTATION;
	static const float STICK_DEADZONE;
	static const float LIFT_INCREMENT;
	static const float STINGER_FOLLOW_UP;
	static const float STINGER_FOLLOW_DOWN;
};

#endif /* SRC_OPERATORCONTROL_H_ */
