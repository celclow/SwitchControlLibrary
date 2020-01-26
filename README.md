# Switch Control Library

## 概要

Arduino を Switch コントローラーとして認識させます。

## 使い方

VID=0x0f0d, PID=0x0092 へ変更してボードへ書き込んでください。

変更方法はボードによって異なりますが、SparkFun Pro Micro の場合、下記ファイルを変更してください。
`~/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.12/boards.txt`

## 操作方法

メソッドの定義は `SwitchControlLibrary.h` を参照。

- ボタンを押す

  ```
  // Aボタンを押す
  SwitchControlLibrary().PressButtonA();
  ```

- ボタンを離す

  ```
  // Aボタンを離す
  SwitchControlLibrary().ReleaseButtonA();
  ```

- ハット

  Hat の定義は `SwitchControlLibrary.h` を参照。

  ```
  // ハットを左へ
  SwitchControlLibrary().MoveHat(Hat::LEFT);
  ```

* スティック

  Stick の定義は `SwitchControlLibrary.h` を参照。

  ```
  // MoveLeftStick(uint8_t lx, uint8_t ly);
  // lx x軸座標(0〜255)
  // ly y軸座標(0〜255)

  // 左スティックを左へ(数値の場合)
  SwitchControlLibrary().MoveLeftStick(0, 128);
  ```

## ライセンス

[MIT](https://github.com/celclow/SwitchControlLibrary/blob/master/LICENSE)
