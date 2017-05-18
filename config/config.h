#ifndef __CONFIG_H__
#define __CONFIG_H__

typedef struct _config_t config_t;

/*
   Init config file
   Return NULL if init fail
 */
config_t *cfg_init(const char *cfg_file);

int cfg_get_int(config_t *cfg, const char *key);

const char *cfg_get_str(config_t *cfg, const char *key);

void cfg_close(config_t *cfg);

#endif
