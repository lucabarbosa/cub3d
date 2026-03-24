NAME = cub3d

# --- COMPILADOR E FLAGS ---
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD -MP -I ./src -I ./libft -I ./mlx

# --- DEBUG & SANITIZER FLAGS ---
DFLAGS = -g3 -O0
AFLAGS = $(DFLAGS) -fsanitize=address

# --- BIBLIOTECAS ---
MLX    = mlx/libmlx_Linux.a
LIBFT  = libft/libft.a
LIBS   = -L ./libft -l:libft.a -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

# --- CORES PARA OUTPUT ---
GREEN  = \033[0;32m
RED    = \033[0;31m
BLUE   = \033[0;34m
YELLOW = \033[0;33m
RESET  = \033[0m

# --- DIRETÓRIOS ---
SRCS_DIR  = src
OBJS_DIR  = objs
DEBUG_DIR = debug
ASAN_DIR  = asan

# --- ARQUIVOS ---
SRCS := $(shell find $(SRCS_DIR) -type f -name "*.c")

OBJS       := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_DEBUG := $(patsubst $(SRCS_DIR)/%.c, $(DEBUG_DIR)/%.o, $(SRCS))
OBJS_ASAN  := $(patsubst $(SRCS_DIR)/%.c, $(ASAN_DIR)/%.o, $(SRCS))

TARGET       = $(NAME)
DEBUG_TARGET = $(DEBUG_DIR)/$(NAME)
ASAN_TARGET  = $(ASAN_DIR)/$(NAME)

DEPS := $(OBJS:.o=.d) $(OBJS_DEBUG:.o=.d) $(OBJS_ASAN:.o=.d)

# --- REGRAS PRINCIPAIS ---
all: $(MLX) $(LIBFT) $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBS) -o $@
	@printf "$(GREEN)🚀 Release binary created at $@$(RESET)\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# --- BIBLIOTECAS ---
$(MLX):
	@make -s -C mlx
	@printf "$(GREEN)✅ Minilibx compiled!$(RESET)\n"

$(LIBFT):
	@make -s -C libft
	@printf "$(GREEN)✅ Libft compiled!$(RESET)\n"

# --- DEBUG ---
debug: $(MLX) $(LIBFT) $(DEBUG_TARGET)

$(DEBUG_TARGET): $(OBJS_DEBUG)
	@mkdir -p $(DEBUG_DIR)
	@$(CC) $(CFLAGS) $(DFLAGS) $(CPPFLAGS) $(OBJS_DEBUG) $(LIBS) -o $@
	@printf "$(GREEN)🛠️  Debug binary created at $@$(RESET)\n"

$(DEBUG_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DFLAGS) $(CPPFLAGS) -c $< -o $@

# --- ASAN ---
asan: $(MLX) $(LIBFT) $(ASAN_TARGET)

$(ASAN_TARGET): $(OBJS_ASAN)
	@mkdir -p $(ASAN_DIR)
	@$(CC) $(CFLAGS) $(AFLAGS) $(CPPFLAGS) $(OBJS_ASAN) $(LIBS) -o $@
	@printf "$(YELLOW)⚠️  ASan binary created at $@$(RESET)\n"

$(ASAN_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(AFLAGS) $(CPPFLAGS) -c $< -o $@

# --- ATALHOS DE FERRAMENTAS ---
gdb: debug
	@printf "$(BLUE)🐛 Starting GDB...$(RESET)\n"
	gdb $(DEBUG_TARGET) -tui

valgrind: debug
	@printf "$(BLUE)🔍 Starting Valgrind...$(RESET)\n"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(DEBUG_TARGET)

run_asan: asan
	@printf "$(YELLOW)🧪 Running with ASan...$(RESET)\n"
	./$(ASAN_TARGET)

run: $(TARGET)
	@printf "$(GREEN)🎲 Running $(NAME)...$(RESET)\n"
	@./$(TARGET)

# --- LIMPEZA ---
clean:
	@make -s clean -C libft
	@make -s clean -C mlx
	@rm -rf $(OBJS_DIR) $(DEBUG_DIR) $(ASAN_DIR)
	@printf "$(RED)🧹 Object folders removed.$(RESET)\n"

fclean: clean
	@make -s fclean -C libft
	@printf "$(RED)💥 Binaries removed.$(RESET)\n"

re: fclean all

-include $(DEPS)
.PHONY: all clean fclean re debug asan gdb valgrind run_asan run