# 🏆 Contestas.io
> **Quiz Interativo via Terminal em C — Arquitetura e Fluxo do Sistema**

---

## 💡 1. O Conceito Pedagógico

O principal objetivo do projeto é a **separação estrita entre Dados (Persistência) e Lógica (Código)**.
* O jogo inicia consumindo um banco de dados de **perguntas pré-definidas** armazenadas em um arquivo `.txt`.
* O motor em C processa essas informações dinamicamente a cada partida.
* O sistema permite evolução contínua através do cadastro opcional de novas perguntas e da atualização instantânea do ranking de jogadores.

---

## 🏗️ 2. Arquitetura e Ciclo de Execução
*(Utilize este diagrama para mostrar à banca o caminho exato que os dados fazem durante o uso do programa)*

```mermaid
flowchart TD
    %% Customização de Estilos (Clean e Seguro para o GitHub)
    classDef arquivo fill:#fff5f5,stroke:#ffc9c9,stroke-width:2px;
    classDef hub fill:#e6f7ff,stroke:#bae7ff,stroke-width:2px;
    classDef fluxo fill:#f6ffed,stroke:#d9f7be,stroke-width:2px;

    %% Nós do Sistema
    A["📄 perguntas.txt <br> (Perguntas Pré-definidas)"]:::arquivo
    B["⚙️ Menu Principal <br> (Loop do main.c)"]:::hub
    
    C["🎮 Opção 1: Jogar"]:::fluxo
    D["🧠 Alocação RAM <br> (malloc + embaralhar)"]:::hub
    E["🏆 ranking.txt <br> (Atualizado após cada rodada)"]:::arquivo
    
    F["📊 Opção 2: Ver Ranking"]:::fluxo
    G["👨‍🏫 Opção 3: Modo Professor"]:::fluxo

    %% Conexões do Fluxo
    B --> C
    B --> F
    B --> G

    %% Execução do Jogo
    A -->|1. Carrega dados| C
    C --> D
    D -->|2. Grava Top 10 imediato| E
    
    %% Visualização do Ranking
    F -->|Lê placar| E
    
    %% Expansão pelo Professor
    G -->|3. Opcional: Adiciona novas perguntas| A
