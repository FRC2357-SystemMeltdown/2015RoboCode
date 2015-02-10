#include "WPILib.h"
#include "DriveController.h"
#include "LiftController.h"
#include "OperatorController.h"
#include "AutonomousControl.h"

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
class Robot: public SampleRobot
{

	DriveController driveController;
	LiftController liftController;
	OperatorController operatorController;
	AutonomousControl autonomousControl;

	int pressedButton;
	float rotation;
	float forward;
	float strafe;

public:
	Robot() :
			driveController(1, 0, 2, 3),
			liftController(4, 1),
			operatorController(driveController, liftController, 0, 1),
			autonomousControl(driveController, liftController)
	{
		pressedButton=0;
		rotation=0;
		forward=0;
		strafe=0;
	}

	/**
	 * Runs the motors with Mecanum drive.
	 */
	void Autonomous()
	{
		if (IsAutonomous() && IsEnabled())
		{
			autonomousControl.RunModeOne();
		}
	}

	void OperatorControl()
	{
		driveController.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{
			operatorController.Run();
			Wait(0.005); // wait 5ms to avoid hogging CPU cycles
		}
	}

};

START_ROBOT_CLASS(Robot);
