#ifndef LFS_CONFIG_H
#define LFS_CONFIG_H

// Activer/désactiver des logs ou vérifications internes
#define LFS_NO_ASSERT     1
#define LFS_NO_ERROR      0
#define LFS_NO_WARN       0
#define LFS_NO_DEBUG      1
// LittleFS configuration (lfs_config.h)
#define LFS_BLOCK_SIZE 256    // Taille de bloc
#define LFS_PAGE_SIZE 256     // Taille de page
#define LFS_LOOKAHEAD_SIZE 16 // Taille de la recherche anticipée
#define LFS_BLOCK_CYCLES 500  // Nombre de cycles de bloc
#define LFS_PROG_SIZE 256     // Taille de la programmation
#define LFS_READ_SIZE 256     // Taille de lecture
#define LFS_CACHE_SIZE 256    // Taille du cache

// Configuration de la mémoire utilisée
#define LFS_STORAGE_SIZE (32 * 1024) // 32 Ko, ajustable en fonction de la mémoire disponible

// Exemple de configuration pour utiliser la SRAM3
#define LFS_CFG       \
{                    \
    .read_size  = LFS_READ_SIZE,  \
    .prog_size  = LFS_PROG_SIZE,  \
    .block_size = LFS_BLOCK_SIZE, \
    .block_cycles = LFS_BLOCK_CYCLES, \
    .page_size  = LFS_PAGE_SIZE,  \
    .cache_size = LFS_CACHE_SIZE, \
    .lookahead_size = LFS_LOOKAHEAD_SIZE,  \
    .name_max   = LFS_NAME_MAX  \
}

#endif

