// Roni Naftalovich 319049060, roni100400100400@gmail.com
#include "tree.hpp"
#include "Complex.hpp"

template <typename T>
TreeNode<T>::TreeNode(T key) : key(key) {}

template <typename T>
void TreeNode<T>::addChild(TreeNode<T>* child) {
    children.push_back(child);
}

template <typename T>
T TreeNode<T>::get_value() const {
    return key;
}

template <typename T>
Tree<T>::Tree(int k) : root(nullptr), k(k) {}

template <typename T>
Tree<T>::~Tree() {
    deleteTree(root);
}

template <typename T>
void Tree<T>::deleteTree(TreeNode<T>* node) {
    if (node) {
        for (auto& child : node->children) {
            deleteTree(child);
        }
        delete node;
    }
}

template <typename T>
void Tree<T>::add_root(const T& key) {
    if (root) {
        root->key = key;
    } else {
        root = new TreeNode<T>(key);
    }
}

template <typename T>
void Tree<T>::add_sub_node(TreeNode<T>* parent, const T& value) {
    if (parent->children.size() >= static_cast<size_t>(k)) {
        throw std::out_of_range("Number of children exceeds k");
    }
    TreeNode<T>* new_node = new TreeNode<T>(value);
    parent->children.push_back(new_node);
}


template <typename T>
TreeNode<T>* Tree<T>::getRoot() {
    return root;
}

template <typename T>
typename Tree<T>::PreOrderIterator Tree<T>::begin_pre_order() {
    return PreOrderIterator(root);
}

template <typename T>
typename Tree<T>::PreOrderIterator Tree<T>::end_pre_order() {
    return PreOrderIterator(nullptr);
}

template <typename T>
typename Tree<T>::PostOrderIterator Tree<T>::begin_post_order() {
    return PostOrderIterator(root);
}

template <typename T>
typename Tree<T>::PostOrderIterator Tree<T>::end_post_order() {
    return PostOrderIterator(nullptr);
}

template <typename T>
typename Tree<T>::InOrderIterator Tree<T>::begin_in_order() {
    return InOrderIterator(root);
}

template <typename T>
typename Tree<T>::InOrderIterator Tree<T>::end_in_order() {
    return InOrderIterator(nullptr);
}

template <typename T>
typename Tree<T>::BFSIterator Tree<T>::begin_bfs_scan() {
    return BFSIterator(root);
}

template <typename T>
typename Tree<T>::BFSIterator Tree<T>::end_bfs_scan() {
    return BFSIterator(nullptr);
}

template <typename T>
typename Tree<T>::DFSIterator Tree<T>::begin_dfs_scan() {
    return DFSIterator(root);
}

template <typename T>
typename Tree<T>::DFSIterator Tree<T>::end_dfs_scan() {
    return DFSIterator(nullptr);
}

template <typename T>
typename Tree<T>::HeapIterator Tree<T>::begin_heap() {
    return HeapIterator(root);
}

template <typename T>
typename Tree<T>::HeapIterator Tree<T>::end_heap() {
    return HeapIterator(nullptr);
}



template <typename T>
void Tree<T>::renderTree(SDL_Renderer* renderer, TTF_Font* font, TreeNode<T>* node, int x, int y, int offsetX, int offsetY) const {
    if (!node) return;

    // Draw the node rectangle
    SDL_Rect rect = {x, y, 60, 50};  // Increase the width to 60
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue color
    SDL_RenderFillRect(renderer, &rect);

    // Render the key text with precision
    std::ostringstream keyTextStream;

    if constexpr (std::is_same_v<T, Complex>) {
        keyTextStream << node->get_value().real << (node->get_value().imag >= 0 ? "+" : "") << node->get_value().imag << "i";
    } else {
        keyTextStream << node->get_value();  // For regular numbers
    }

    std::string keyText = keyTextStream.str();
    
    SDL_Color textColor = {255, 255, 255, 255};  // White color
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, keyText.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    int textWidth = 0;
    int textHeight = 0;
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
    SDL_Rect textRect = {x + (60 - textWidth) / 2, y + (50 - textHeight) / 2, textWidth, textHeight};  // Adjust the x coordinate
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

    // Adjust horizontal spacing for level 1
    int adjustedOffsetX = (y == offsetY) ? offsetX * 2.4 : offsetX*0.92;  // Double the spacing for level 1

    // Draw the children
    int childX = x - adjustedOffsetX * (node->children.size() - 1) / 2;
    int childY = y + offsetY;
    for (TreeNode<T>* child : node->children) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red color for lines
        SDL_RenderDrawLine(renderer, x + 30, y + 50, childX + 30, childY);  // Adjust the x coordinate
        renderTree(renderer, font, child, childX, childY, adjustedOffsetX / 2, offsetY * 0.9);
        childX += adjustedOffsetX;
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& tree) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        os << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return os;
    }

    if (TTF_Init() == -1) {
        os << "Could not initialize SDL_ttf: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return os;
    }

    SDL_Window* window = SDL_CreateWindow("Tree GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        os << "Could not create window: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return os;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        os << "Could not create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return os;
    }

   TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/ubuntu/UbuntuMono-RI.ttf", 18);
    if (!font) {
        os << "Could not open font: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return os;
    }

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White color for background
        SDL_RenderClear(renderer);

        tree.renderTree(renderer, font, tree.root, 400, 50, 220, 180);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return os;
}
