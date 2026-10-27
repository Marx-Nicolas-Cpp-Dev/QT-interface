#!/usr/bin/env bash
set -e
pkill -x Xvfb || true
pkill -x openbox || true
pkill -x x11vnc || true
pkill -f websockify || true
Xvfb :1 -screen 0 1280x720x24 >/dev/null 2>&1 &
sleep 1
DISPLAY=:1 openbox >/dev/null 2>&1 &
x11vnc -display :1 -nopw -forever -shared -bg -quiet
websockify -D --web=/usr/share/novnc 6080 localhost:5900
echo "GUI screen ready on port 6080 (open /vnc.html)"