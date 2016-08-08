SOURCES = team.c programmer/programmer.c \
	programmer/actions/eat_sushi.c \
	programmer/actions/fix_bug.c

all: main team

main: hackathon.c
	gcc -g $< -o $@

team: $(SOURCES)
	gcc -g $? -o $@ -lpthread -I.
