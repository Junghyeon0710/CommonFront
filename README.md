# CommonFront

<br>

Common UI 기반으로 메뉴/시작화면/옵션 등을 일관성 있게 구성된 플러그인


- 지원 버전 5.6
- [업데이트 노트](https://github.com/Junghyeon0710/CommonFront/wiki/%EC%97%85%EB%8D%B0%EC%9D%B4%ED%8A%B8-%EB%85%B8%ED%8A%B8)

<br>

## 설치
1. `zip` 파일 다운로드
2. 압축후 `Plugins` 폴더에 `CommonFront`로 넣기
3. 프로젝트 실행
4. 에디터에서 편집 -> 플러그인에서 `CommonFront`플러그인 활성화

<br>
<br>

## 특징
- **로비 시퀀스 추가** : 시작 시 자동 재생 지원
- **4가지 레이아웃 스택 제공** : Front End, Game HUD, Game Menu, Modal
- **레이아웃 템플릿 제공** : 위젯 레이아웃 일관성 유지 가능
- **블루프린트 비동기 액션 제공**  
  - 레이아웃 스택에 위젯을 쉽게 푸시 가능  
  - 모달창을 쉽게 푸시 가능
 
<br>
<br>

## 사용법

### 플러그인 활성화
<img width="1840" height="179" alt="Image" src="https://github.com/user-attachments/assets/c89189ea-3e34-41fc-a82f-c7998bd065b4" />

- **Common Front** 플러그인을 활성화합니다.

---

<br>


### 로비 시퀀스 배치
1. 원하는 로비 레벨에서  
   `Plugins/CommonFront Content/Maps/Sequence` 경로에 있는 **SEQ_Lobby**를 배치합니다.
<img width="1263" height="362" alt="Image" src="https://github.com/user-attachments/assets/540d7ac9-94cd-4e3f-9d5d-5f60d4f41cf7" />


<br>
<br>
<br>


2. 배치 후 시퀀스를 열고 필요한 값으로 수정합니다.
<img width="2105" height="677" alt="Image" src="https://github.com/user-attachments/assets/c1d8b304-8ab0-48b8-8915-5a803dcd30b5" />

---

<br>

### 로비 레벨 게임모드 변경
<img width="713" height="475" alt="Image" src="https://github.com/user-attachments/assets/54417c4f-3bf2-4115-80fe-818b4316b5ab" />

- 해당 레벨에 월드 세팅에 가서 게임모드를 **BP_FrontendGameMode**로 변경해주세요.

<br>

---

### 로딩 설정
<img width="2488" height="1355" alt="Image" src="https://github.com/user-attachments/assets/81eafc46-5e5d-43df-85bb-fd531e85c97e" />

- `Project Settings` → `Game` → `FrontendLoadingScreenSettings`에서 원하는 값으로 수정합니다.
- **SoftLoadingScreenWidgetClass**: 로딩 화면에 사용할 위젯 클래스
- **HoldLoadingScreenExtrasSeconds**: 로딩 화면이 유지되는 시간(초)
- **bShouldLoadingScreenInEditor**: 에디터 실행 시 로딩 화면 표시 여부

<br>
<br>

## Preview

<br>

### Loading
<img width="1909" height="977" alt="Image" src="https://github.com/user-attachments/assets/2d191fea-ca6a-48eb-873d-6577ae0277f6" />

<br>

### MainMenu Frontend
<img width="1920" height="977" alt="Image" src="https://github.com/user-attachments/assets/475c645d-9d70-4530-a917-bd39187a26bf" />

<br>

### Stroy Frontend
<img width="1912" height="958" alt="image" src="https://github.com/user-attachments/assets/507585c7-7ea8-4147-98b9-d545f2f7a67f" />

<br>

### Options Frontend

<br>
<br>

- Gameplay Option
<img width="1905" height="973" alt="image" src="https://github.com/user-attachments/assets/07333d91-dc53-4e98-b72f-7d61adc30f6b" />

<br>
<br>

- Audio Option
<img width="1893" height="966" alt="image" src="https://github.com/user-attachments/assets/f4b2a2f4-885f-4d5c-a368-0028dc24f950" />

<br>
<br>

- Video Option
<img width="1908" height="954" alt="image" src="https://github.com/user-attachments/assets/e4dad5be-95ae-432c-9132-ba4bf6df4542" />

<br>
<br>

- Control Option
<img width="1886" height="950" alt="image" src="https://github.com/user-attachments/assets/142216c5-3a08-4fcc-ac45-06ed1e60d283" />

<br>

## Credit Frontend
<img width="1914" height="961" alt="image" src="https://github.com/user-attachments/assets/cb2600c1-bc68-4482-9b9f-b43fe249e214" />

<br>

## Quit Modal
<img width="971" height="422" alt="image" src="https://github.com/user-attachments/assets/cd52c831-8dd9-45be-81b0-a029ce8f30e8" />


