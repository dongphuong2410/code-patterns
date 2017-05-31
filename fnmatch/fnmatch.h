#ifndef __FNMATCH_H__
#define __FNMATCH_H__

/**
  * @brief Matching a filename against a pattern
  * @param pattern String pattern
  * @param filename Filename to match
  * @return Return 0 if match, return 1 if not match, return -1 if error happens
  *
  * Currently, function just support maximum pattern len 256
  * and maximum directory level is 13
  */
int fnmatch(const char *pattern, const char *filename);


#endif
