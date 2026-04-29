# 🎮 Cub3D - Raycaster 3D Engine

Um mecanismo 3D baseado em raycasting implementado em C, inspirado no clássico Wolfenstein 3D. Render de texturas em tempo real com suporte a múltiplos mapas e texturas customizáveis.

## 📋 Requisitos

### Dependências do Sistema
- **gcc** ou **clang** (compilador C)
- **X11** (servidor gráfico Linux)
- **libXext** e **libX11** (bibliotecas X11)
- **libm** (biblioteca matemática)
- **libbsd** (para funcionalidades BSD)

### Instalação de Dependências (Ubuntu/Debian)
```bash
sudo apt-get install gcc make libx11-dev libxext-dev libbsd-dev
```

### Instalação de Dependências (Fedora/RHEL)
```bash
sudo dnf install gcc make libX11-devel libXext-devel libbsd-devel
```

## 🔨 Compilação

### Build Release (Otimizado)
```bash
make
```
Cria o binário otimizado em `bin/cub3d`

### Build Debug (Com símbolos de debug)
```bash
make debug
```
Cria o binário com informações de debug em `debug/cub3d`

### Build com AddressSanitizer (Detecção de memória)
```bash
make asan
```
Cria o binário com ASAN habilitado em `asan/cub3d`

### Limpeza
```bash
make clean      # Remove arquivos objeto
make fclean     # Remove todos os artefatos gerados
make re         # Recompila tudo
```

## ▶️ Execução

### Sintaxe Básica
```bash
./bin/cub3d <caminho_do_mapa>
```

### Exemplos
```bash
./bin/cub3d maps/map.cub
./bin/cub3d maps/cube.cub
./bin/cub3d maps/forty_two_school.cub
```

### Mapas Disponíveis
- `maps/map.cub` - Mapa padrão
- `maps/cube.cub` - Mapa em forma de cubo
- `maps/alley.cub` - Beco
- `maps/demon.cub` - Mapa demon
- `maps/forty_two_school.cub` - Mapa da escola 42
- `maps/test.cub` - Mapa de teste
- `maps/vazio.cub` - Mapa vazio

## 🎮 Controles

| Tecla | Ação |
|-------|------|
| `W` | Mover para frente |
| `A` | Mover para esquerda |
| `S` | Mover para trás |
| `D` | Mover para direita |
| `Seta Esquerda` | Virar à esquerda |
| `Seta Direita` | Virar à direita |
| `ESC` | Sair do jogo |

## 🗺️ Formato do Mapa e Texturas

### Estrutura do Arquivo .cub

Um arquivo de mapa `.cub` define os parâmetros de renderização e o layout do mapa. Exemplo:

```
NO ./assets/textures/north.xpm
SO ./assets/textures/south.xpm
WE ./assets/textures/west.xpm
EA ./assets/textures/east.xpm

F  0,0,0
C  225,30,1

111111111
101000001
100000001
100N00001
100000001
100000001
100000001
100000001
111111111
```

### Elementos Obrigatórios

| Elemento | Descrição |
|----------|-----------|
| `NO` | Textura da parede Norte |
| `SO` | Textura da parede Sul |
| `WE` | Textura da parede Oeste |
| `EA` | Textura da parede Leste |
| `F` | Cor do piso (R,G,B) |
| `C` | Cor do teto (R,G,B) |

### Simbologia do Mapa

| Símbolo | Significado |
|---------|------------|
| `1` | Parede |
| `0` | Espaço vazio |
| `N` | Posição inicial do jogador (olhando para norte) |
| `S` | Posição inicial do jogador (olhando para sul) |
| `E` | Posição inicial do jogador (olhando para leste) |
| `W` | Posição inicial do jogador (olhando para oeste) |

### Paleta de Cores (RGB)

#### Cores Disponíveis para Texturas

Você pode usar qualquer textura no formato XPM. As texturas padrão estão em `assets/textures/`:

```
assets/textures/
├── north.xpm
├── south.xpm
├── west.xpm
└── east.xpm
```

#### Cores para Piso e Teto

As cores são especificadas em formato RGB (0-255 para cada componente):

```
F  255,0,0      # Vermelho
C  0,255,0      # Verde
F  0,0,255      # Azul
C  128,128,128  # Cinza
F  255,255,255  # Branco
C  0,0,0        # Preto
```

### Como Criar Suas Próprias Texturas

1. Crie uma imagem em formato XPM
2. Coloque em `assets/textures/`
3. Atualize o arquivo `.cub` com o caminho da textura
4. Execute o programa

Exemplo:
```
NO ./assets/textures/my_north_texture.xpm
SO ./assets/textures/my_south_texture.xpm
WE ./assets/textures/my_west_texture.xpm
EA ./assets/textures/my_east_texture.xpm

F  100,50,200
C  200,100,50
```

## 📸 Capturas de Tela

### Vista do Jogo Principal

![Gameplay](img/gameplay_01.png)

![Gameplay](img/gameplay_02.png)

### Mapa em Miniatura

O jogo inclui um minimapa no canto superior esquerdo que mostra:
- A posição do jogador
- A direção em que o jogador olha (linhas vermelhas)
- O layout do mapa (paredes em preto, espaço vazio trasparente)

![Minimapa](img/minimap.png)

## 🏗️ Estrutura do Projeto

```
cub3d/
├── assets/
│   └── textures/          # Arquivos de textura (.xpm)
├── includes/
│   ├── cub3d.h            # Header principal
│   └── parser.h           # Parser de mapas
├── libft/                 # Biblioteca C personalizada
├── mlx/                   # MinilibX (renderização gráfica)
├── src/
│   ├── main.c             # Ponto de entrada
│   ├── utils.c            # Funções utilitárias
│   ├── draw/              # Funções de desenho
│   ├── game_loop/         # Loop principal do jogo
│   ├── map/               # Lógica de mapa
│   ├── parser/            # Parser de arquivos .cub
│   ├── player/            # Lógica do jogador
│   ├── rays/              # Engine de raycasting
│   ├── render/            # Renderização de paredes
│   ├── scene/             # Renderização de cena
│   ├── textures/          # Gerenciamento de texturas
│   └── utils/             # Utilidades diversas
├── maps/                  # Arquivos de mapa (.cub)
├── Makefile               # Script de compilação
└── README.md              # Este arquivo
```

## 🔧 Troubleshooting

### Erro: "cannot open shared object file"
```bash
# Recompile a biblioteca MLX
cd mlx && make clean && make
cd ..
make re
```

### Erro: "X11 not found"
Instale as dependências de desenvolvimento do X11:
```bash
sudo apt-get install libx11-dev libxext-dev  # Ubuntu/Debian
sudo dnf install libX11-devel libXext-devel  # Fedora/RHEL
```

### O jogo não responde aos controles
- Certifique-se de que a janela do jogo está em foco (clique nela)
- Verifique se nenhuma outra tecla está presa

### Texturas não aparecem
- Verifique se o caminho no arquivo `.cub` está correto (caminho relativo a partir do diretório atual)
- Verifique se a textura está em formato XPM válido

## 📚 Referências

- [MinilibX Documentation](https://github.com/42Paris/minilibx-linux)
- [Raycasting Algorithm](https://en.wikipedia.org/wiki/Ray_casting)
- [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D)

