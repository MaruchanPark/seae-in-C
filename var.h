// Encoder
int LOOP;
int STRIDE = 2;
int FILTER_LENGTH = 31;
int INPUT_CHANNELS[11] = {1, 16, 32, 32, 64, 64, 128, 128, 256, 256, 512} ;
int OUTPUT_CHANNELS[11] = {16, 32, 32, 64,64,128,128,256,256,512,1024};
int INPUT_LENGTH[11] = {16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16};
int OUTPUT_LENGTH[11] = {8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8};
float coeff_preemph = 0.95;

float* x_in_0;
float* ENC_F_0; float* ENC_F_1; float* ENC_F_2; float* ENC_F_3; float* ENC_F_4; float* ENC_F_5;
float* ENC_F_6; float* ENC_F_7; float* ENC_F_8; float* ENC_F_9; float* ENC_F_10;
float* ENC_b_0; float* ENC_b_1; float* ENC_b_2; float* ENC_b_3; float* ENC_b_4; float* ENC_b_5;
float* ENC_b_6; float* ENC_b_7; float* ENC_b_8; float* ENC_b_9; float* ENC_b_10;
float* ENC_alpha_0; float* ENC_alpha_1; float* ENC_alpha_2; float* ENC_alpha_3; float* ENC_alpha_4; 
float* ENC_alpha_5; float* ENC_alpha_6; float* ENC_alpha_7; float* ENC_alpha_8; float* ENC_alpha_9; 
float* ENC_alpha_10;
float* x_out_0;  float* x_out_1;  float* x_out_2;  float* x_out_3;  float* x_out_4;
float* x_out_5;  float* x_out_6;  float* x_out_7;  float* x_out_8;  float* x_out_9;
float* x_out_10;
float* skip_0;  float* skip_1;   float* skip_2;  float* skip_3;  float* skip_4;  float* skip_5;
float* skip_6;  float* skip_7;  float* skip_8;  float* skip_9;

// Decoder
int DEC_LOOP;
int DEC_OUTPUT_CHANNELS[11] = {512, 256, 256, 128, 128, 64, 64, 32, 32, 16, 1};
int DEC_INPUT_LENGTH[11] = {8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
int DEC_OUTPUT_LENGTH[11] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
int DEC_INPUT_CHANNELS[11] = {1024, 512, 256, 256, 128, 128, 64, 64, 32, 32, 16};

float* DEC_in;
float* DEC_out_0; float* DEC_out_1; float* DEC_out_2; float* DEC_out_3; float* DEC_out_4;
float* DEC_out_5; float* DEC_out_6; float* DEC_out_7; float* DEC_out_8; float* DEC_out_9;
float* DEC_out_10;
float* DEC_F_0;  float* DEC_F_1;  float* DEC_F_2;  float* DEC_F_3;  float* DEC_F_4;  float* DEC_F_5;
float* DEC_F_6;  float* DEC_F_7;  float* DEC_F_8;  float* DEC_F_9;  float* DEC_F_10;
float* DEC_b_0;  float* DEC_b_1;  float* DEC_b_2;  float* DEC_b_3;  float* DEC_b_4;  float* DEC_b_5;
float* DEC_b_6;  float* DEC_b_7;  float* DEC_b_8;  float* DEC_b_9;  float* DEC_b_10;
float* DEC_alpha_0;  float* DEC_alpha_1;  float* DEC_alpha_2;  float* DEC_alpha_3;
float* DEC_alpha_4;  float* DEC_alpha_5;  float* DEC_alpha_6;  float* DEC_alpha_7;
float* DEC_alpha_8;  float* DEC_alpha_9;  float* DEC_alpha_10;
float* skipped_0;  float* skipped_1;  float* skipped_2;  float* skipped_3;  float* skipped_4;
float* skipped_5;  float* skipped_6;  float* skipped_7;  float* skipped_8;  float* skipped_9;
