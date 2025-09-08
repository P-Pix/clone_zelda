# 🗡️ Zelda Like Game

Un clone de Zelda créé en C++ avec SFML, featuring un monde ouvert avec monstres, combats et exploration.

## ✨ Fonctionnalités

- 🎮 Contrôles fluides du joueur (WASD/Flèches)
- ⚔️ Système de combat avec épée
- 👹 IA de monstres avec patterns de mouvement
- 💎 Système de collectibles (rubis, cœurs)
- 📦 Coffres interactifs
- 🗺️ Génération de cartes
- 🎨 Sprites et animations

## 🔧 Prérequis

### Dépendances
- **C++17** ou plus récent
- **SFML 2.5+** pour les graphiques et le son
- **CMake 3.16+** (optionnel, pour build moderne)
- **Make** (pour build traditionnel)

### Installation des dépendances

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install libsfml-dev g++ make cmake
```

#### Ou via le Makefile
```bash
make install-deps
```

## 🚀 Compilation et Exécution

### Méthode moderne (CMake)
```bash
mkdir build && cd build
cmake ..
make
./ZeldaLike
```

### Méthode traditionnelle (Makefile)
```bash
# Build release
make release
make run

# Build debug avec symbols
make debug
make run-debug

# Analyse mémoire
make valgrind
```

### Commandes utiles
```bash
make clean        # Nettoyer les fichiers de build
make install-deps # Installer les dépendances SFML
```

## 🎮 Contrôles

| Touche | Action |
|--------|--------|
| `WASD` ou `↑↓←→` | Déplacement |
| `Espace` | Attaque à l'épée |
| `Échap` | Quitter |

## 🏗️ Architecture

```
src/
├── main.cpp           # Point d'entrée
├── Game/              # Logique principale du jeu
├── GamesWindow/       # Gestion de la fenêtre SFML
├── Joueur/            # Classe joueur et contrôles
├── Monster/           # IA et comportement des monstres
├── MapGenerator/      # Génération procédurale de cartes
└── [autres modules]/  # Autres systèmes de jeu
```

## 📊 Compatibilité

| OS | Support |
|----|---------|
| Ubuntu 20.04+ | ✅ Testé |
| Debian 10+ | ✅ Compatible |
| Fedora 30+ | ✅ Compatible |
| Arch Linux | ✅ Compatible |
| Windows | ⚠️ Non testé |
| macOS | ⚠️ Non testé |

## 🐛 Debug et Développement

```bash
# Compilation avec informations de debug
make debug

# Analyse mémoire avec Valgrind
make valgrind

# Documentation (si Doxygen installé)
doxygen Doxyfile
```

## 📝 TODO et Améliorations

- [ ] Support multi-niveaux
- [ ] Système de sauvegarde
- [ ] Sons et musique
- [ ] Menus d'interface
- [ ] Optimisations performances
- [ ] Tests unitaires

## 🤝 Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :
1. Fork le projet
2. Créer une branche feature
3. Commiter vos changements
4. Ouvrir une Pull Request

## 📄 Licence

Projet personnel © 2021 Guillaume LEMONNIER

## 🔗 Ressources

- [SFML Documentation](https://www.sfml-dev.org/documentation/2.5.1/)
- [SFML Download](https://www.sfml-dev.org/download/sfml/2.5.1/)
- [C++ Reference](https://en.cppreference.com/)
