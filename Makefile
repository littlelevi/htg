  CC = g++
  CFLAGS  = -std=c++17 -g 
  TARGET  = dracula
  INCLUDE = include/
  THEMES  = include/themes/ 
  CONFIG  = ~/.config/helix/
  DESTDIR = ~/.config/helix/themes/

copy: $(TARGET)
	@echo
	@echo ----------------------------------------------------
	@echo Creating $(TARGET)-htg.toml
	@echo ----------------------------------------------------
	./$(TARGET) > $(TARGET)-htg.toml
	@echo
	@echo ----------------------------------------------------
	@echo Copying $(TARGET)-htg.toml to your $(DESTDIR)
	@echo ----------------------------------------------------
	cp $(TARGET)-htg.toml $(DESTDIR)$(TARGET)-htg.toml
	@echo
	@echo ====================================================
	@echo Now add theme=$(TARGET)-htg to your config.toml in $(CONFIG)
	@echo ====================================================
 
$(TARGET): obj/$(TARGET).o 
	$(CC) obj/$(TARGET).o -o $(TARGET)
	
obj/$(TARGET).o: objs $(TARGET).cpp
	$(CC) -c $(TARGET).cpp $(CFLAGS) -I $(INCLUDE) -I $(THEMES) -o obj/$(TARGET).o

objs:
	mkdir -p obj
			
.PHONY: clean
clean:
	rm -dr obj