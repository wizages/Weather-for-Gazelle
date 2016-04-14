ARCHS = armv7 arm64
TARGET = :clang

include $(THEOS)/makefiles/common.mk
TARGET_LIB_EXT = -

TWEAK_NAME = WeatherforGazelle
WeatherforGazelle_FILES = $(wildcard *.xm)
WeatherforGazelle_FRAMEWORKS = UIKit
WeatherforGazelle_EXTRA_FRAMEWORKS = Gazelle CoreLocation
WeatherforGazelle_INSTALL_PATH = /Library/Application Support/Gazelle/Views/com.wizages.weather/

include $(THEOS_MAKE_PATH)/tweak.mk

before-stage::
	find . -name ".DS_Store" -delete

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather$(ECHO_END)
	$(ECHO_NOTHING)cp Info.plist $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/$(ECHO_END)
	$(ECHO_NOTHING)cp Icon.png $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/$(ECHO_END)
	$(ECHO_NOTHING)cp Icon@2x.png $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/$(ECHO_END)
	$(ECHO_NOTHING)cp Icon@3x.png $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/$(ECHO_END)

	# If your view has some settings uncomment this, otherwise you can remove this
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/Preferences$(ECHO_END)
	# finally
	$(ECHO_NOTHING)cp Preferences/Root.plist $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/Preferences/$(ECHO_END)
	#dam it
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/Assets$(ECHO_END)
	# fuck
	$(ECHO_NOTHING)cp Assets/*.png $(THEOS_STAGING_DIR)/Library/Application\ Support/Gazelle/Views/com.wizages.weather/Assets/$(ECHO_END)

after-install::
	install.exec "killall -9 SpringBoard"
