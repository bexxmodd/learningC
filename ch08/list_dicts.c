#define NAME_MAX 14 /* longest filename component */


typedef struct {    /* portable directory entry: */
    long ino;       /* inode number */
    char name[NAME_MAX+1];
} Dirent;

typedef struct {    /* minimal DIR: no buffering, etc. */
    int fd;         /* file descriptor for directory */
    Dirent d;       /* the directory entry */
} DIR;


DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);


char *name;
struct stat stbuf;
int stats(char *, struct stat *);

stat(name, stbuf);