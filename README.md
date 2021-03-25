# SSD Project
- Make a Virtual SSD

### Purpose
- SSD 제품을 테스트 할 수 있는 Shell 제작
  - SSD를 가상으로 프로그래밍하여 구현
  - Test Shell 프로그램을 제작하여 SSD 동작을 테스트

### To Do
- SSD : HW를 SW로 구현
- Test Shell Application : Shell
- Vertification : SSD를 Test

### Part
  | SSD | Shell | Vertification |
  | --- | --- | --- |
  | [RhoHeeSeon](https://github.com/RhoHeeSeon) | [dlwlgn](https://github.com/dlwlgn) | [KimUJin3359](https://github.com/KimUJin3359) |

---

### SSD란?
#### 저장할 수 있는 공간
- 저장핤 수 있는 최소 공간의 사이즈 4KB
- 각 공간마다 LBA(Logical Block Address)라는 주소를 가짐
- SSD는 OS에서 File System을 거쳐 Read, Write, Sync, Unmap 등 다양한 명령어를 수행

#### 구조
- 컨트롤러
  - OS는 FileSystem을 거쳐 LBA 주소에 특정 값 요청
  - 컨트롤러가 이 명령어들을 받아 Nand Flasy Memory에 저장
- NAND Flash Memory
  - 실제로 값들이 저장되는 곳
  - 컨트롤러에 의해 값이 저장

#### 구현해야할 가상 SSD
- Read, Write만 존재
- LBA 단위는 4 Byte(0x00000000 ~ 0xFFFFFFFF)
- LBA 0 ~ 99
  - 총 400 Byte 저장 가능

#### 구현해야할 Shell
- 사용 가능 명령어
  - write : SSD에 write
  - read : SSD에 read
  - exit : shell 종료
  - help : 도움말 출력
  - fullwrite : 0~99번 index에 write
  - fullread : 0~99번 index 전체를 읽음
- 입력받은 매개변수 유효성 검사 수행
  - Format
  - LBA 범위 0 ~ 99
  - A ~ F, 0 ~ 9까지 숫자 범위만 허용
- 없는 명령어를 수행하는 경우 "INVALID COMMAND"

#### 구현해야할 Vertification
- Test 1
  - fullwrite 수행
  - fullread를 수행 후, write 한 값대로 read가 되는지 확인
- Test 2
  - 0 ~ 5번 LBA에 30번 Write (임의의 값)
  - 0 ~ 5번 LBA에 0x12345678로 1회 Over Write
  - 후에 Write한 값으로 정상적으로 읽히는지 확인
- Test 3
  - 일부러 틀린 test case를 만듬
  - 2번과 같이 수행했을 때, 변경되지 않는 상황
