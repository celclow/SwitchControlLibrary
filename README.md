# Switch Control Library

## 概要

Arduino を Switch コントローラーとして認識させます。

**v2 系 は v1 系とは互換性がありません。**
過去バージョンは[Release](https://github.com/celclow/SwitchControlLibrary/releases)ページよりダウンロードできます。

## 使い方

VID=0x0f0d, PID=0x0092 へ変更してボードへ書き込んでください。

変更方法はボードによって異なりますが、SparkFun Pro Micro の場合、下記ファイルを変更してください。
`~/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.12/boards.txt`

## 操作方法

- ボタンを押す

  - `pressButton(uint8_t button)`

    ```
    SwitchControlLibrary().pressButton(Button::A); // Aボタンを押す
    SwitchControlLibrary().pressButton(Button::B); // Bボタンを押す
    ```

  - `releaseButton(uint8_t button)`

    ```
    SwitchControlLibrary().releaseButton(Button::A); // Aボタンを離す
    SwitchControlLibrary().releaseButton(Button::B); // Bボタンを離す
    ```

  - `Button` 定義一覧

    ```
    Button::Y
    Button::B
    Button::A
    Button::X
    Button::L
    Button::R
    Button::ZL
    Button::ZR
    Button::MINUS
    Button::PLUS
    Button::LCLICK
    Button::RCLICK
    Button::HOME
    Button::CAPTURE
    ```

- ハット

  - `moveHat(uint8_t hat)`

    ```
    SwitchControlLibrary().moveHat(Hat::UP); // ハットは上
    SwitchControlLibrary().moveHat(Hat::RIGHT); // ハットは右
    ```

  - `Hat` 定義一覧

    ```
    Hat::UP
    Hat::UP_RIGHT
    Hat::RIGHT
    Hat::DOWN_RIGHT
    Hat::DOWN
    Hat::DOWN_LEFT
    Hat::LEFT
    Hat::UP_LEFT
    Hat::NEUTRAL
    ```

  - `pressHat(uint8_t hat_button)` `releaseHat(uint8_t hat_button)`

    ```
    SwitchControlLibrary().pressHat(HatButton::UP) // ハットは上
    SwitchControlLibrary().pressHat(HatButton::RIGHT) // ハットは右上
    SwitchControlLibrary().releaseHat(HatButton::UP) // ハットは右
    SwitchControlLibrary().releaseHat(HatButton::RIGHT) // ハットはニュートラル
    ```

  - `HatButton` 定義一覧

    ```
    HatButton::UP
    HatButton::RIGHT
    HatButton::DOWN
    HatButton::LEFT
    ```

- スティック

  - `moveLeftStick(uint8_t lx, uint8_t ly)` `moveRightStick(uint8_t rx, uint8_t ry)`

    - `lx` `ly` `rx` `ry` には、0〜255 の値を指定します。

    ```
    SwitchControlLibrary().moveLeftStick(0, 128) // 左スティックは左
    SwitchControlLibrary().moveLeftStick(128, 128) // 左スティックはニュートラル
    SwitchControlLibrary().moveLeftStick(255, 128) // 左スティックは右
    SwitchControlLibrary().moveLeftStick(Stick::MIN, Stick::NEUTRAL) // 左スティックは左
    SwitchControlLibrary().moveLeftStick(Stick::MAX, Stick::NEUTRAL) // 左スティックは右
    ```

  - `Stick` 定義一覧

    ```
    Stick::MIN
    Stick::NEUTRAL
    Stick::MAX
    ```

- `sendReport()`

  `sendReport()` を実行したタイミングでキーが送信されます。

  ```
  SwitchControlLibrary().pressButton(Button::A); // ニュートラル
  SwitchControlLibrary().pressButton(Button::B); // ニュートラル
  SwitchControlLibrary().sendReport() // A、Bボタンが同時に送信される
  ```

## ライセンス

[MIT](https://github.com/celclow/SwitchControlLibrary/blob/master/LICENSE)
