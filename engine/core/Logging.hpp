#pragma once
#include <iostream>
#define SIM_LOG_INFO(msg)  std::cout << "[INFO] "  << msg << std::endl
#define SIM_LOG_WARN(msg)  std::cout << "[WARN] "  << msg << std::endl
#define SIM_LOG_ERR(msg)   std::cerr << "[ERROR] " << msg << std::endl