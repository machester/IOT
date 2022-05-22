#idf_component_register(SRCS "lcd_main.c"
#							"st7789_driver.c"
#                    INCLUDE_DIRS ".")
set(COMPONENT_SRCS "lcd_main.c"
					"../st7789_test/st7789_driver.c")
set(COMPONENT_ADD_INCLUDEDIRS "../st7789_test")

register_component()
