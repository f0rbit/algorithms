/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int read = 0;
        while (read < n) {
            int n_read = read4(buf + read);
            if (n_read < 4) {
                read += n_read;
                break;
            }
            read += n_read;
        }
        buf[n] = '\0';
        return read;
    }
};
