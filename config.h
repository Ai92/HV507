#ifndef CONFIG_H_
#define CONFIG_H_

// UART
#define BAUDRATE 9600
#define TIMEOUT 1000

// MV507
#define CLOCK_PIN 5    // 通信クロック用のピン
#define LATCH_PIN 6    // シフトレジスタ設定用のフラグピン（Highなら書き込み可）
#define DATA_PIN 7     // シフトレジスタ設定用のデータピン
#define POLARITY_PIN 8 // 極性反転用のピン
#define BLANKING_PIN 9 //
#define DIRECTION_PIN 10

#endif
