type props('a) = 'a;

[@bs.deriving abstract]
type optionsLayout = {
  [@bs.optional]
  backgroundColor: string,
};

type optionsTopBarTitleComponent;

[@bs.obj]
external optionsTopBarTitleComponent:
  (
    ~id: string=?,
    ~name: string=?,
    ~alignment: [@bs.string] [ | `center | `fill]=?,
    ~passProps: props('a)=?,
    unit
  ) =>
  optionsTopBarTitleComponent =
  "";

[@bs.deriving abstract]
type optionsTopBarTitle = {
  [@bs.optional]
  text: string,
  [@bs.optional]
  fontSize: float,
  [@bs.optional]
  color: ReactNative.Color.t,
  [@bs.optional]
  fontFamily: string,
  [@bs.optional]
  height: float,
  [@bs.optional]
  alignment: string,
  [@bs.optional]
  component: optionsTopBarTitleComponent,
};
type optionsTopBarSubTitle;
type imageRequireSource;

type optionsTopBarBackButton;
[@bs.obj]
external optionsTopBarBackButton:
  (
    ~icon: imageRequireSource=?,
    ~visible: bool=?,
    ~title: string=?,
    ~showTitle: bool=?,
    ~color: ReactNative.Color.t=?,
    unit
  ) =>
  optionsTopBarBackButton =
  "";

[@bs.deriving abstract]
type optionsTopBarBackground = {
  [@bs.optional]
  color: ReactNative.Color.t,
  [@bs.optional]
  clipToBounds: bool,
  [@bs.optional]
  translucent: bool,
  [@bs.optional]
  blur: bool,
};

type iconInsets = {
  top: float,
  left: float,
  bottom: float,
  right: float,
};

type optionsTopBarButton;

[@bs.obj]
external optionsTopBarButton:
  (
    ~id: string=?,
    ~icon: imageRequireSource=?,
    ~systemItem: [@bs.string] [
                   | [@bs.as "done"] `done_
                   | `cancel
                   | `edit
                   | `save
                   | `add
                   | `flexibleSpace
                   | `fixedSpace
                   | `compose
                   | `reply
                   | `action
                   | `organize
                   | `bookmarks
                   | `search
                   | `refresh
                   | `stop
                   | `camera
                   | `trash
                   | `play
                   | `pause
                   | `rewind
                   | `fastForward
                   | `undo
                   | `redo
                 ]
                   =?,
    ~text: string=?,
    ~fontFamily: string=?,
    ~enabled: bool=?,
    ~disableIconTint: bool=?,
    ~color: ReactNative.Color.t=?,
    ~disabledColor: ReactNative.Color.t=?,
    ~testID: string=?,
    ~showAsAction: string=?,
    ~iconInsets: iconInsets=?,
    unit
  ) =>
  optionsTopBarButton =
  "";

type optionsLargeTitle;
type androidDensityNumber = float;

[@bs.deriving abstract]
type optionsTopBar = {
  [@bs.optional]
  visible: bool,
  [@bs.optional]
  animate: bool,
  [@bs.optional]
  hideOnScroll: bool,
  [@bs.optional]
  leftButtonColor: ReactNative.Color.t,
  [@bs.optional]
  rightButtonColor: ReactNative.Color.t,
  [@bs.optional]
  leftButtonDisabledColor: ReactNative.Color.t,
  [@bs.optional]
  rightButtonDisabledColor: ReactNative.Color.t,
  [@bs.optional]
  drawBehind: bool,
  [@bs.optional]
  testID: string,
  [@bs.optional]
  title: optionsTopBarTitle,
  [@bs.optional]
  subTitle: optionsTopBarSubTitle,
  [@bs.optional]
  backButton: optionsTopBarBackButton,
  [@bs.optional]
  leftButtons: array(optionsTopBarButton),
  [@bs.optional]
  rightButtons: array(optionsTopBarButton),
  [@bs.optional]
  background: optionsTopBarBackground,
  [@bs.optional]
  barStyle: string,
  [@bs.optional]
  noBorder: bool,
  [@bs.optional]
  searchBar: bool,
  [@bs.optional]
  searchBarHiddenWhenScrolling: bool,
  [@bs.optional]
  searchBarPlaceholder: string,
  [@bs.optional]
  hideNavBarOnFocusSearchBar: bool,
  [@bs.optional]
  largeTitle: optionsLargeTitle,
  [@bs.optional]
  height: androidDensityNumber,
  [@bs.optional]
  borderColor: ReactNative.Color.t,
  [@bs.optional]
  borderHeight: androidDensityNumber,
  [@bs.optional]
  elevation: androidDensityNumber,
  [@bs.optional]
  topMargin: float,
};

type navigationOptions;
[@bs.obj]
external navigationOptions:
  (~layout: optionsLayout=?, ~topBar: optionsTopBar=?, unit) =>
  navigationOptions =
  "";

type layoutComponent;
[@bs.obj]
external layoutComponent:
  (
    ~id: string=?,
    ~name: string=?,
    ~options: navigationOptions=?,
    ~passProps: props('a)=?,
    unit
  ) =>
  layoutComponent =
  "";

type layoutStackChildren;
[@bs.obj]
external layoutStackChildren:
  (~component: layoutComponent=?) => layoutStackChildren =
  "";

type layoutStack;
[@bs.obj]
external layoutStack:
  (
    ~id: string,
    ~children: array(layoutStackChildren),
    ~options: navigationOptions=?,
    unit
  ) =>
  layoutStack =
  "";

[@bs.deriving abstract]
type layout('p) = {
  [@bs.optional]
  component: layoutComponent,
  [@bs.optional]
  stack: layoutStack,
};

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external showModal: layout('a) => unit = "showModal";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external push: (string, layout('a)) => unit = "push";
[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external pushChild: (string, layoutStackChildren) => unit = "push";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external dismissModal: string => unit = "dismissModal";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external popToRoot: string => unit = "popToRoot";
