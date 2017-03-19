>tbox for free pascal
>- 封装c库tbox（https://github.com/tboox/tbox)中协程相关的api为dll，供free pascal调用
>- 开发环境 win7　64位 free pascal 3.0
>- 开发ide lazarus 1.6.2 tbox1.6.1
>- 源代码src目录
>- src/tbox_share将c库tbox中协程相关的api封装为dll
>- 示例见demo目录
>- 测试见test目录

>tbox_share编译方法
>- 先下载c库tbox(1.6.1)并编译，编译方法见https://github.com/tboox/tbox
>- 将c库tbox编译后的include和lib复制到与tbox_share下tbox子目录中,如下所示
>>- tbox_shared
>>>- tbox
>>>>-  include
>>>>-  lib
>- 在tbox_share目录下运行xmake进行编译
>- 配置成编译64位应用
>- xmake config --arch=x64
>- xmake
