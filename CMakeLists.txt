cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

project(DGEngine)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
    add_definitions(-Wall -stdlib=libc++)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(NOT BEOS)
        add_definitions(-Wall)
    endif()
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules")

option(DGENGINE_MOVIE_SUPPORT "Enable Movie support" TRUE)
option(DGENGINE_DIABLO_FORMAT_SUPPORT "Enable Diablo 1-2 file format support" TRUE)
option(DGENGINE_FALLBACK_TO_LOWERCASE_FILENAME "Enable falling back to all lowercase names if file is not found" TRUE)

if(DGENGINE_MOVIE_SUPPORT)
    find_package(FFmpeg COMPONENTS avcodec avformat avutil swscale)
endif()
find_package(PhysFS REQUIRED)
find_package(SFML 2.5 REQUIRED system window graphics network audio)

include_directories(./src)

set(SOURCE_FILES
    src/Main.cpp
    src/Alignment.h
    src/Anchor.h
    src/Animation.cpp
    src/Animation.h
    src/AnimationType.h
    src/AudioSource.h
    src/BaseAnimation.cpp
    src/BaseAnimation.h
    src/BindableText.cpp
    src/BindableText.h
    src/BitmapButton.cpp
    src/BitmapButton.h
    src/BitmapFont.cpp
    src/BitmapFont.h
    src/BitmapText.cpp
    src/BitmapText.h
    src/BlendMode.h
    src/Button.cpp
    src/Button.h
    src/CachedImagePack.cpp
    src/CachedImagePack.h
    src/Circle.cpp
    src/Circle.h
    src/CmdLineUtils.cpp
    src/CmdLineUtils.h
    src/CompositeTexture.cpp
    src/CompositeTexture.h
    src/DrawableText.h
    src/Dun.cpp
    src/Dun.h
    src/Event.cpp
    src/Event.h
    src/EventManager.h
    src/FadeInOut.cpp
    src/FadeInOut.h
    src/FileUtils.cpp
    src/FileUtils.h
    src/Font.h
    src/FreeTypeFont.h
    src/Game.cpp
    src/Game.h
    src/GameUtils.cpp
    src/GameUtils.h
    src/IfCondition.cpp
    src/IfCondition.h
    src/IgnoreResource.h
    src/Image.cpp
    src/Image.h
    src/ImageUtils.cpp
    src/ImageUtils.h
    src/InputEvent.cpp
    src/InputEvent.h
    src/InputText.cpp
    src/InputText.h
    src/LoadingScreen.cpp
    src/LoadingScreen.h
    src/Menu.cpp
    src/Menu.h
    src/Min.cpp
    src/Min.h
    src/Movie2.cpp
    src/Movie2.h
    src/Palette.cpp
    src/Palette.h
    src/Panel.cpp
    src/Panel.h
    src/Pcx.cpp
    src/Pcx.h
    src/PhysFSStream.cpp
    src/PhysFSStream.h
    src/Queryable.h
    src/Rectangle.cpp
    src/Rectangle.h
    src/ResourceManager.cpp
    src/ResourceManager.h
    src/Scrollable.cpp
    src/Scrollable.h
    src/ShaderManager.cpp
    src/ShaderManager.h
    src/StreamReader.h
    src/StringButton.cpp
    src/StringButton.h
    src/StringText.cpp
    src/StringText.h
    src/Text.cpp
    src/Text.h
    src/TextureInfo.h
    src/TextUtils.cpp
    src/TextUtils.h
    src/TileSet.cpp
    src/TileSet.h
    src/UIObject.cpp
    src/UIObject.h
    src/Variable.cpp
    src/Variable.h
    src/VarOrPredicate.h
    src/Actions/ActAction.h
    src/Actions/ActAnimation.h
    src/Actions/ActAudio.h
    src/Actions/ActButton.h
    src/Actions/ActCondition.h
    src/Actions/ActCursor.h
    src/Actions/ActDrawable.h
    src/Actions/ActEvent.h
    src/Actions/ActFade.h
    src/Actions/ActFocus.h
    src/Actions/ActFont.h
    src/Actions/ActGame.h
    src/Actions/ActImage.h
    src/Actions/ActInputText.h
    src/Actions/ActIO.h
    src/Actions/Action.h
    src/Actions/ActiontList.h
    src/Actions/ActItem.h
    src/Actions/ActLevel.h
    src/Actions/ActLevelObject.h
    src/Actions/ActLoad.h
    src/Actions/ActLoadingScreen.h
    src/Actions/ActMenu.h
    src/Actions/ActMount.h
    src/Actions/ActMovie.h
    src/Actions/ActPalette.h
    src/Actions/ActPlayer.h
    src/Actions/ActQuest.h
    src/Actions/ActRandom.h
    src/Actions/ActResource.h
    src/Actions/ActScrollable.h
    src/Actions/ActShader.h
    src/Actions/ActSound.h
    src/Actions/ActText.h
    src/Actions/ActVariable.h
    src/Actions/ActVisibility.h
    src/Game/Classifier.cpp
    src/Game/Classifier.h
    src/Game/Classifiers.h
    src/Game/ColorLevelLayer.cpp
    src/Game/ColorLevelLayer.h
    src/Game/FlagsVector.h
    src/Game/Formula.cpp
    src/Game/Formula.h
    src/Game/Formulas.h
    src/Game/fsa.h
    src/Game/GameHashes.h
    src/Game/GameProperties.cpp
    src/Game/GameProperties.h
    src/Game/Inventories.h
    src/Game/Inventory.cpp
    src/Game/Inventory.h
    src/Game/Item.cpp
    src/Game/Item.h
    src/Game/ItemClass.cpp
    src/Game/ItemClass.h
    src/Game/ItemLocation.h
    src/Game/Level.cpp
    src/Game/Level.h
    src/Game/LevelCell.cpp
    src/Game/LevelCell.h
    src/Game/LevelFlags.h
    src/Game/LevelLayer.h
    src/Game/LevelMap.cpp
    src/Game/LevelMap.h
    src/Game/LevelObject.cpp
    src/Game/LevelObject.h
    src/Game/LevelObjectClass.cpp
    src/Game/LevelObjectClass.h
    src/Game/LevelObjectClassDefaults.h
    src/Game/LevelSurface.cpp
    src/Game/LevelSurface.h
    src/Game/LightMap.h
    src/Game/LightSource.h
    src/Game/Number.h
    src/Game/PairXY.h
    src/Game/PathFinder.cpp
    src/Game/PathFinder.h
    src/Game/Player.cpp
    src/Game/Player.h
    src/Game/PlayerClass.cpp
    src/Game/PlayerClass.h
    src/Game/Quest.cpp
    src/Game/Quest.h
    src/Game/SimpleLevelObject.cpp
    src/Game/SimpleLevelObject.h
    src/Game/SimpleLevelObjectClass.h
    src/Game/Spell.cpp
    src/Game/Spell.h
    src/Game/TextureLevelLayer.cpp
    src/Game/TextureLevelLayer.h
    src/Game/TilesetLevelLayer.cpp
    src/Game/TilesetLevelLayer.h
    src/Game/stlastar.h
    src/Game/Save/SaveItem.cpp
    src/Game/Save/SaveItem.h
    src/Game/Save/SaveLevel.cpp
    src/Game/Save/SaveLevel.h
    src/Game/Save/SavePlayer.cpp
    src/Game/Save/SavePlayer.h
    src/Game/Save/SaveProperties.h
    src/Game/Save/SaveSimpleLevelObject.cpp
    src/Game/Save/SaveSimpleLevelObject.h
    src/Game/Save/SaveUtils.cpp
    src/Game/Save/SaveUtils.h
    src/ImageContainers/ImageContainer.h
    src/ImageContainers/SimpleImageContainer.cpp
    src/ImageContainers/SimpleImageContainer.h
    src/Json/JsonParser.h
    src/Json/JsonUtils.cpp
    src/Json/JsonUtils.h
    src/Parser/ParseAction.cpp
    src/Parser/ParseAction.h
    src/Parser/ParseAnimation.cpp
    src/Parser/ParseAnimation.h
    src/Parser/ParseAudio.cpp
    src/Parser/ParseAudio.h
    src/Parser/ParseAudioCommon.cpp
    src/Parser/ParseAudioCommon.h
    src/Parser/ParseButton.cpp
    src/Parser/ParseButton.h
    src/Parser/ParseCircle.cpp
    src/Parser/ParseCircle.h
    src/Parser/ParseCompositeTexture.cpp
    src/Parser/ParseCompositeTexture.h
    src/Parser/ParseCondition.cpp
    src/Parser/ParseCondition.h
    src/Parser/ParseCursor.cpp
    src/Parser/ParseCursor.h
    src/Parser/ParseEvent.cpp
    src/Parser/ParseEvent.h
    src/Parser/ParseFile.cpp
    src/Parser/ParseFile.h
    src/Parser/ParseFont.cpp
    src/Parser/ParseFont.h
    src/Parser/ParseIcon.cpp
    src/Parser/ParseIcon.h
    src/Parser/ParseImage.cpp
    src/Parser/ParseImage.h
    src/Parser/ParseImageContainer.cpp
    src/Parser/ParseImageContainer.h
    src/Parser/ParseInputText.cpp
    src/Parser/ParseInputText.h
    src/Parser/ParseKeyboard.cpp
    src/Parser/ParseKeyboard.h
    src/Parser/ParseLoadingScreen.cpp
    src/Parser/ParseLoadingScreen.h
    src/Parser/ParseMenu.cpp
    src/Parser/ParseMenu.h
    src/Parser/ParseMenuButton.cpp
    src/Parser/ParseMenuButton.h
    src/Parser/ParseMountFile.cpp
    src/Parser/ParseMountFile.h
    src/Parser/ParseMovie.cpp
    src/Parser/ParseMovie.h
    src/Parser/ParsePalette.cpp
    src/Parser/ParsePalette.h
    src/Parser/ParsePanel.cpp
    src/Parser/ParsePanel.h
    src/Parser/ParsePredicate.cpp
    src/Parser/ParsePredicate.h
    src/Parser/Parser.cpp
    src/Parser/Parser.h
    src/Parser/ParseRectangle.cpp
    src/Parser/ParseRectangle.h
    src/Parser/ParserProperties.h
    src/Parser/ParseScrollable.cpp
    src/Parser/ParseScrollable.h
    src/Parser/ParseSound.cpp
    src/Parser/ParseSound.h
    src/Parser/ParseText.cpp
    src/Parser/ParseText.h
    src/Parser/ParseTexture.cpp
    src/Parser/ParseTexture.h
    src/Parser/ParseTexturePack.cpp
    src/Parser/ParseTexturePack.h
    src/Parser/ParseVariable.cpp
    src/Parser/ParseVariable.h
    src/Parser/Game/ParseClassifier.cpp
    src/Parser/Game/ParseClassifier.h
    src/Parser/Game/ParseItem.cpp
    src/Parser/Game/ParseItem.h
    src/Parser/Game/ParseItemClass.cpp
    src/Parser/Game/ParseItemClass.h
    src/Parser/Game/ParseLevel.cpp
    src/Parser/Game/ParseLevel.h
    src/Parser/Game/ParseLevelObject.cpp
    src/Parser/Game/ParseLevelObject.h
    src/Parser/Game/ParseLevelObjectClass.cpp
    src/Parser/Game/ParseLevelObjectClass.h
    src/Parser/Game/ParsePlayer.cpp
    src/Parser/Game/ParsePlayer.h
    src/Parser/Game/ParsePlayerClass.cpp
    src/Parser/Game/ParsePlayerClass.h
    src/Parser/Game/ParseQuest.cpp
    src/Parser/Game/ParseQuest.h
    src/Parser/Game/ParseSpell.cpp
    src/Parser/Game/ParseSpell.h
    src/Parser/Utils/ParseUtils.cpp
    src/Parser/Utils/ParseUtils.h
    src/Parser/Utils/ParseUtilsIdx.cpp
    src/Parser/Utils/ParseUtilsIdx.h
    src/Parser/Utils/ParseUtilsKey.cpp
    src/Parser/Utils/ParseUtilsKey.h
    src/Parser/Utils/ParseUtilsVal.cpp
    src/Parser/Utils/ParseUtilsVal.h
    src/Predicates/Predicate.h
    src/Predicates/PredIO.h
    src/Predicates/PredItem.h
    src/Predicates/PredLevelObject.h
    src/Predicates/PredPlayer.h
    src/SFML/CompositeSprite.cpp
    src/SFML/CompositeSprite.h
    src/SFML/Image2.h
    src/SFML/Music2.cpp
    src/SFML/Music2.h
    src/SFML/MusicLoops.cpp
    src/SFML/MusicLoops.h
    src/SFML/SFMLUtils.cpp
    src/SFML/SFMLUtils.h
    src/SFML/Sprite2.cpp
    src/SFML/Sprite2.h
    src/SFML/Text2.cpp
    src/SFML/Text2.h
    src/SFML/VertexArray2.cpp
    src/SFML/VertexArray2.h
    src/SFML/View2.cpp
    src/SFML/View2.h
    src/TexturePacks/BitmapFontTexturePack.cpp
    src/TexturePacks/BitmapFontTexturePack.h
    src/TexturePacks/CachedTexturePack.cpp
    src/TexturePacks/CachedTexturePack.h
    src/TexturePacks/IndexedTexturePack.cpp
    src/TexturePacks/IndexedTexturePack.h
    src/TexturePacks/RectTexturePack.cpp
    src/TexturePacks/RectTexturePack.h
    src/TexturePacks/SimpleTexturePack.cpp
    src/TexturePacks/SimpleTexturePack.h
    src/TexturePacks/StackedTexturePack.cpp
    src/TexturePacks/StackedTexturePack.h
    src/TexturePacks/TexturePack.cpp
    src/TexturePacks/TexturePack.h
    src/Utils/EasedValue.h
    src/Utils/EasingFunctions.h
    src/Utils/ElapsedTime.h
    src/Utils/FixedArray.h
    src/Utils/FixedMap.h
    src/Utils/Helper2D.h
    src/Utils/iterator_tpl.h
    src/Utils/LRUCache.h
    src/Utils/NumberVector.h
    src/Utils/ReverseIterable.h
    src/Utils/Utils.cpp
    src/Utils/Utils.h
)

if(FFmpeg_FOUND)
    SET(SOURCE_FILES ${SOURCE_FILES}
        src/sfeMovie/AudioStream.cpp
        src/sfeMovie/AudioStream.hpp
        src/sfeMovie/Demuxer.cpp
        src/sfeMovie/Demuxer.hpp
        src/sfeMovie/Movie.cpp
        src/sfeMovie/Movie.hpp
        src/sfeMovie/MovieImpl.cpp
        src/sfeMovie/MovieImpl.hpp
        src/sfeMovie/Stream.cpp
        src/sfeMovie/Stream.hpp
        src/sfeMovie/StreamSelection.hpp
        src/sfeMovie/Timer.cpp
        src/sfeMovie/Timer.hpp
        src/sfeMovie/TimerPriorities.hpp
        src/sfeMovie/VideoStream.cpp
        src/sfeMovie/VideoStream.hpp
    )
else()
    add_definitions(-DUSE_SFML_MOVIE_STUB)
endif()

if(DGENGINE_DIABLO_FORMAT_SUPPORT)
    SET(SOURCE_FILES ${SOURCE_FILES}
        src/DS1.cpp
        src/DS1.h
        src/Game/LevelHelper.cpp
        src/Game/LevelHelper.h
        src/ImageContainers/CELImageContainer.cpp
        src/ImageContainers/CELImageContainer.h
        src/ImageContainers/CL2ImageContainer.cpp
        src/ImageContainers/CL2ImageContainer.h
        src/ImageContainers/DC6ImageContainer.cpp
        src/ImageContainers/DC6ImageContainer.h
        src/ImageContainers/DCCImageContainer.cpp
        src/ImageContainers/DCCImageContainer.h
        src/ImageContainers/DT1ImageContainer.cpp
        src/ImageContainers/DT1ImageContainer.h
    )
else()
    add_definitions(-DNO_DIABLO_FORMAT_SUPPORT)
endif()

if(DGENGINE_FALLBACK_TO_LOWERCASE_FILENAME)
    add_definitions(-DFALLBACK_TO_LOWERCASE_FILENAME)
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} stdc++fs)

if(FFmpeg_FOUND)
    include_directories(${FFmpeg_INCLUDES})
    target_link_libraries(${PROJECT_NAME} ${FFmpeg_LIBRARIES})
endif()

if(PHYSFS_FOUND)
    include_directories(${PHYSFS_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${PHYSFS_LIBRARY})
endif()

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
