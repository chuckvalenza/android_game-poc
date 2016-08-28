#!/usr/bin/env sh
adb install -r bin/oxyhw-debug.apk
adb shell am start -n org.oxygine.oxyhw/org.oxygine.oxyhw.MainActivity
