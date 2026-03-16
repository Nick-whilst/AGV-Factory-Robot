# -*- coding: utf-8 -*-
"""
AGV 二维码识别程序 - 基于树莓派零W + USB摄像头
功能：实时扫描地面二维码，识别内容并通过串口发送给ESP32
作者：Qwen（AI助手）
"""

import cv2
import pyzbar.pyzbar as pyzbar
import serial
import time

# 配置串口（根据实际连接修改）
# Linux下常用：/dev/ttyUSB0
# MacOS：/dev/cu.usbserial-XXXX
# Windows：COM3
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)

def decode_qr_code(frame):
    """解码二维码"""
    decoded_objects = pyzbar.decode(frame)
    for obj in decoded_objects:
        data = obj.data.decode('utf-8')
        print(f"Detected QR Code: {data}")
        return data
    return None

def main():
    # 打开摄像头
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("Error: Cannot open camera!")
        return

    print("Starting QR Scanner... Press 'q' to quit.")

    while True:
        ret, frame = cap.read()
        if not ret:
            continue

        # 调整图像大小（提高处理速度）
        frame = cv2.resize(frame, (640, 480))

        # 解码二维码
        qr_data = decode_qr_code(frame)

        if qr_data:
            # 发送数据到ESP32
            ser.write(f"QR:{qr_data}\n".encode())
            print(f"Sent to ESP32: QR:{qr_data}")

        # 显示画面
        cv2.imshow("QR Scanner", frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # 释放资源
    cap.release()
    cv2.destroyAllWindows()
    ser.close()

if __name__ == "__main__":
    main()