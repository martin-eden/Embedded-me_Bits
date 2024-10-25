#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_Bits

# Uninstall dependencies
arduino-cli lib uninstall \
  me_Console \
  me_UartSpeeds \
  me_BaseTypes
