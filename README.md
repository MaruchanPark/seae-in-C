# Speech Enhancement Auto-Encoder in C
This code only supports inference, and shares same structure with [SEAE](https://github.com/MaruchanPark/SEAE)
## Parameters:
* Please download the trained [parameters](https://drive.google.com/file/d/10v5-fI1fFHyh9fPi2lvD5xsk7DKClQk_/view?usp=sharing).

* Unzip and place it in the same path as the main code.

## Usage:
### Inference

* 16bit signed integer input is normalized into 32bit floating point(-1 ~ 1).

compile
```
make
```

execution
```
./a.out > result.txt&
```


<img src="assets/INPUT.png" width="400"> <img src="assets/RESULT.png" width="400">
