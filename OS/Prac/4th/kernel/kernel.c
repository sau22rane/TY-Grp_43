void some_function () {
}

void main () {
    char * video_memory = 0xb8000 ;
    * video_memory = 'XX';
    some_function ();
}