// faster, but uses more space since it is expanded everywhere
// also potential for bugs if called like isupper(*line++)
#define isupper(x) ('A'<=(x) && (x)<= 'Z') ? 1 : 0;

// slower since function call, but uses less space.
// outside of speed no weird side effects
int isupper(char c){
    return 'A'<= c && c <= 'Z';
}
