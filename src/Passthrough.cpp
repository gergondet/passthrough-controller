#include "Passthrough.h"

Passthrough::Passthrough(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::MCController(rm, dt)
{
  config_.load(config);
  solver().addConstraintSet(contactConstraint);
  solver().addConstraintSet(kinematicsConstraint);
  solver().addTask(postureTask);
  solver().setContacts({{}});

  mc_rtc::log::success("Passthrough init done ");
}

bool Passthrough::run()
{
  const auto & encoders = robot().encoderValues();
  auto & q = robot().mbc().q;
  for(size_t i = 0; i < robot().module().ref_joint_order().size(); ++i)
  {
    q[robot().jointIndexInMBC(i)][0] = encoders[i];
  }
  return true;
}

void Passthrough::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::MCController::reset(reset_data);
}

CONTROLLER_CONSTRUCTOR("Passthrough", Passthrough)
