#include "lfs.h"
#include <string.h>

// Taille des blocs et nombre de blocs
#define BLOCK_SIZE       256
#define BLOCK_COUNT      128

// Adresse de base de la SRAM3
#define SRAM3_BASE_ADDR  0x30040000

// Déclarer un pointeur vers la mémoire physique de SRAM3
static uint8_t *sram3_storage = (uint8_t *)SRAM3_BASE_ADDR;

// Fonctions pour LittleFS

// Lecture de données depuis SRAM3
int user_provided_block_device_read(const struct lfs_config *c,
                                    lfs_block_t block,
                                    lfs_off_t offset,
                                    void *buffer,
                                    lfs_size_t size) {
    // Lire les données depuis l'adresse SRAM3
    memcpy(buffer, &sram3_storage[block * c->block_size + offset], size);
    return 0;
}

// Programmation (écriture) de données dans SRAM3
int user_provided_block_device_prog(const struct lfs_config *c,
                                    lfs_block_t block,
                                    lfs_off_t offset,
                                    const void *buffer,
                                    lfs_size_t size) {
    // Écrire les données dans l'adresse SRAM3
    memcpy(&sram3_storage[block * c->block_size + offset], buffer, size);
    return 0;
}

// Effacement d'un bloc de SRAM3
int user_provided_block_device_erase(const struct lfs_config *c,
                                     lfs_block_t block) {
    // Effacer le bloc en remplissant de 0xFF
    memset(&sram3_storage[block * c->block_size], 0xFF, c->block_size);
    return 0;
}

// Synchronisation (pas nécessaire ici, mais fourni pour la conformité)
int user_provided_block_device_sync(const struct lfs_config *c) {
    return 0;
}

// Configuration LittleFS
struct lfs_config cfg = {
    .read  = user_provided_block_device_read,
    .prog  = user_provided_block_device_prog,
    .erase = user_provided_block_device_erase,
    .sync  = user_provided_block_device_sync,

    .read_size = 16,          // Taille de lecture
    .prog_size = 16,          // Taille de programmation
    .block_size = BLOCK_SIZE, // Taille des blocs (ici 256 octets)
    .block_count = BLOCK_COUNT, // Nombre de blocs
    .cache_size = 16,         // Taille du cache
    .lookahead_size = 16,     // Taille de la mémoire de prévision
    .block_cycles = 500,      // Nombre de cycles par bloc (pour gestion de wear leveling)
};
