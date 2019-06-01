#include <QCoreApplication>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <string>
#include <cstring>

#define BUFSIZE 1024 //Любое число байт, кратное 16.
using namespace std;

void printCharsAsHex(unsigned char *buf, int len){
    for(int i=0; i<len; i++) printf("0x%02x ", buf[i]);
    printf("\n\n");
}

//General encryption and decryption function example using FILE I/O and AES256 with a 256-bit key.
int do_crypt(char* textin, char* textout, int do_encrypt){
    unsigned char inbuf[BUFSIZE], outbuf[BUFSIZE + EVP_MAX_BLOCK_LENGTH]; //EVP_MAX_BLOCK_LENGTH = 128 бит
    int inlen, outlen;

    cout<<textin<<"\n";

    inlen = strlen(textin);
    cout<<inlen<<"\n";

    for(int i = 0; i < inlen; i++)
        inbuf[i] = textin[i];

    unsigned char key[] = "0123456789abcdeF0123456789abcdeF"; //256 бит
    unsigned char iv[] = "1234567887654321"; //128 бит

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL, do_encrypt);
    OPENSSL_assert(EVP_CIPHER_CTX_key_length(ctx) == 32);
    OPENSSL_assert(EVP_CIPHER_CTX_iv_length(ctx) == 16);
    EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, do_encrypt);

    //for(;;){
    //inlen = fread(inbuf, 1, BUFSIZE, in);
    printf("%d B, In:\n", inlen);
    //if (inlen <= 0) break;
    if(!EVP_CipherUpdate(ctx, outbuf, &outlen, inbuf, inlen)){
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }
    //fwrite(outbuf, 1, outlen, out);
    printf("  %d B, OutU:\n", outlen);
    //printCharsAsHex(outbuf, outlen);
    //}

    if(!EVP_CipherFinal_ex(ctx, outbuf, &outlen)){
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }
    //fwrite(outbuf, 1, outlen, out);
    printf("  %d B, OutF:\n", outlen);
    //printCharsAsHex(outbuf, outlen);

    cout<<outbuf;
    EVP_CIPHER_CTX_free(ctx);
    return 1;
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    //############

    string text1;
    getline(cin, text1);
    int size = text1.length();
    cout<<size<<"\n";
    char* text = new char[size];

    strcpy((char*) text, text1.c_str());
    cout<<text;

    char* textenc = new char[size+16];
    char* textdec = new char[size];

    printf("ENCRYPT:\n\n");
    //FILE *encode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file.txt", "rb");
    //FILE *decode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file1.txt", "wb");
    do_crypt(text, textenc, 1); // 0 - decrypt, 1 - encrypt
    //fclose(encode_file);
    //fclose(decode_file);

    printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n\n");
    printf("DECRYPT:\n\n");

    //encode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file1.txt", "rb");
    //decode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file2.txt", "wb");
   // do_crypt(*textenc, textdec, 0); // 0 - decrypt, 1 - encrypt
    //fclose(encode_file);
    //fclose(decode_file);

    //############

    return a.exec();
}
