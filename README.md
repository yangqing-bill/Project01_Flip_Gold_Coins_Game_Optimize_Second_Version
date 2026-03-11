翻金币游戏 (Coin Flip)
一、项目简介：
《翻金币》是一款基于Qt Widgets框架开发的益智闯关游戏。玩家通过点击金币翻转自身及相邻金币，目标是将所有金币翻至正面（金色）。
游戏包含主菜单、20个精心设计的关卡、音效反馈和胜利动画，代码结构清晰，适合学习Qt游戏开发与面向对象设计。

二、功能特性
1、多关卡挑战：内置20个难度递增的关卡，每个关卡4x4棋盘布局。
2、平滑动画：金币翻转使用逐帧动画，按钮具有弹跳效果，胜利时弹出奖牌动画。
3、音效反馈：点击、翻转、胜利、返回等操作均有音效，音量可配置。
4、配置集中管理：窗口尺寸、动画时长、音效音量等常量统一在Config.h中定义。
5、单例音效管理器：SoundManager负责所有音效的加载与播放，避免重复创建。
6、智能胜利判定：通过动画计数确保所有金币翻转完成后才判定胜利，避免逻辑冲突。
7、内存安全：场景切换时正确释放资源，防止内存泄漏。

三、技术栈：
1、语言：C++17
2、框架：Qt 5/6 (Widgets模块 + Multimedia模块)
3、核心机制：信号槽、事件处理、定时器、属性动画、资源文件
4、设计模式：单例模式（音效管理）、对象组合（界面与逻辑分离）

四、项目结构：
├── Config.h                // 全局配置常量（窗口大小、动画时长、路径等）
├── main.cpp                // 应用程序入口
├── mainwindow.h/cpp        // 主窗口（开始菜单）
├── chooseselevelscene.h/cpp // 关卡选择场景
├── playscene.h/cpp          // 游戏主场景（棋盘与金币）
├── mypushbutton.h/cpp       // 自定义按钮（支持图片切换与弹跳动画）
├── mycoin.h/cpp             // 自定义金币控件（翻转动画与状态管理）
├── soundmanager.h/cpp       // 音效管理器（单例）
├── dataconfig.h/cpp         // 关卡数据配置（20个关卡二维数组）
└── res.qrc/file.qrc         // 资源文件（图片、音效）

五、核心技术：
1、C++17 核心语言特性：使用 constexpr 常量定义游戏配置，利用 nullptr、override 等现代C++语法提升代码健壮性与可读性。
2、Qt Widgets 模块：基于 QMainWindow 构建多窗口场景（主菜单、关卡选择、游戏界面），通过信号槽实现场景间低耦合通信。
3、Qt Multimedia 模块：采用 QSoundEffect 播放短音效（点击、翻转、胜利等），并通过单例管理器统一管理音效对象，避免重复加载。
4、自定义控件与事件处理：
（1）MyPushButton 继承 QPushButton，重写 mousePressEvent / mouseReleaseEvent 实现按下/释放图片切换。
（2）MyCoin 继承 QPushButton，封装正反状态（m_isFront）与逐帧动画（双定时器控制8帧图片切换），重写鼠标事件防止动画中重复点击。
5、Qt 动画框架：使用 QPropertyAnimation 实现按钮弹跳效果（animatePressDown/animatePressUp）和胜利奖牌下落动画，配合 QEasingCurve::OutBounce 增强交互质感。
6、数据驱动设计：DataConfig 类以 QMap<int, QVector<QVector<int>>> 存储20个关卡4x4棋盘数据，通过索引快速加载关卡初始状态。
7、单例模式：SoundManager 使用单例确保全局唯一音效管理器，所有场景共享同一个音效实例，降低资源占用。

六、项目亮点：
1、配置集中管理：将所有魔法数字（窗口尺寸、动画时长、坐标偏移等）抽取至 Config.h 命名空间，实现一键修改，提升可维护性。
2、动画计数胜利判定：引入 m_animatingCount 变量跟踪正在播放动画的金币数量，当计数器归零时才进行胜负判断，避免动画过程中误判，逻辑严谨可靠。
3、内存安全与资源管理：
（1）场景切换时使用 deleteLater() 安全销毁旧场景，防止野指针。
（2）胜利标签（m_winLabel）在返回前及时清理，避免重复创建导致内存泄漏。
（3）自定义控件析构函数中停止并删除定时器，杜绝资源泄露。
4、模块化与低耦合：
（1）音效、关卡数据、自定义控件均独立为类，主逻辑仅依赖接口，便于扩展（如新增关卡格式或音效类型）。
（2）场景间通过信号（chooseSceneBack）通信，不直接持有对方指针，减少耦合。
5、友好的用户体验：
（1）按钮按下/释放有视觉反馈，弹跳动画自然平滑。
（2）金币翻转时播放音效，胜利时弹出奖牌并播放庆祝音效，增强游戏沉浸感。
（3）关卡选择界面按钮上显示数字，鼠标穿透设计确保点击准确。
6、工程化实践：
（1）资源文件（.qrc）统一管理图片和音效，避免路径错误。
（2）使用 qDebug() 输出关键调试信息（如关卡进入、胜利触发），便于跟踪程序运行状态。

七、运行截图：
<img width="319" height="613" alt="image" src="https://github.com/user-attachments/assets/4bc11f77-c90d-4e43-904b-4362dbafe61a" />
<img width="321" height="615" alt="image" src="https://github.com/user-attachments/assets/fccbbbae-a4f2-4e7e-8bfa-9b9fac2142ca" />
<img width="314" height="614" alt="image" src="https://github.com/user-attachments/assets/a4830e71-f607-49e7-9a1d-0497d1e5e5b3" />
<img width="316" height="622" alt="image" src="https://github.com/user-attachments/assets/78e2c3d1-c8c7-43c2-9de4-0087a5130071" />

八、关于作者： 本项目为个人 Qt 学习练习作品，旨在实践自定义控件、动画系统、信号槽通信及游戏开发基础。

